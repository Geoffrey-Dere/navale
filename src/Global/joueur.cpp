#include "joueur.h"

Joueur::Joueur(QString identifiant, NavireFactory* navireFactory,  int nb_navire ,int resistanceNavire,
               bool humain , QObject *parent) : QObject(parent)
{
    m_humain = humain;
    m_identifiant = identifiant;
    m_liste = navireFactory->creerNavire(nb_navire, resistanceNavire);
}

bool Joueur::estHumain(){
    return m_humain;
}

QString Joueur::identifiant(){
    return m_identifiant;
}

QVariant Joueur::getNextNavireAPlacer(){
    return QVariant::fromValue(m_liste.takeFirst());
}

void Joueur::creerMap(QPoint dimension){
    if(m_map == nullptr)
        m_map=new Map(dimension,this);
}


/*
 * dans le cas d'un positionnement non automatique
 */
bool Joueur::addCase(Navire* navire,QList<int>& cases){

    assert(!m_navires.contains(navire));
    qSort(cases.begin(), cases.end(),qGreater<int>());

    QList<int>::ConstIterator ite;
    int compteur = navire->getTaille()-1;
    for(ite=cases.constBegin() ;  ite != cases.constEnd() ; ++ite){
        Position p;
        p.bateau_partie = compteur;
        p.case_id = *ite;
        m_navires.insertMulti(navire, p);
        compteur--;
    }

    //    QHash<QObject*, Position>::const_iterator i = m_navires.find(navire);
    //    while (i != m_navires.end() && i.key() == navire) {
    //        ++i;
    //    }
    return true;
}


void Joueur::placerNavire(Navire* navire,QList<int> cases,bool horizontale){
    addCase(navire, cases);
    navire->setHorizontale(horizontale);
}


//place les bateaux aléatoirements
void Joueur::placementAutomatique(){

    int largeur = m_map->getDimension().x();
    int hauteur = m_map->getDimension().y();

    while (!m_liste.isEmpty()){ // on place chaque navire

        Navire* navire = m_liste.takeFirst();

        bool positionTrouver = false;

        while(!positionTrouver){

            int horizontale = qrand() % 2 ;
            int x = (qrand() % largeur);
            int y = (qrand() % hauteur);

            if(horizontale==1 && x + navire->getTaille() >= largeur)
                continue;
            if(horizontale==0 && y + navire->getTaille() >=  hauteur)
                continue;

            positionTrouver = true;
            navire->setHorizontale(horizontale==1);

            x = horizontale==1? x+navire->getTaille()  : x;
            y = horizontale==0? y+navire->getTaille() : y;

            int position = navire->getTaille()-1;
            for(int i = 0 ; i < navire->getTaille() ; i++){
                int id = m_map->getNumeroCase(x,y);

                // on teste que la carte n'est pas occupé par un autre navire -> à améliorer
                if( ! m_navires.keys(Position{id,0}).empty()){
                    positionTrouver = false;
                    m_navires.remove(navire);
                    break;
                }
                Position p ;
                p.bateau_partie = position;
                p.case_id = id;

                m_navires.insertMulti(navire, p);
                x = horizontale==1? x-1 : x;
                y = horizontale==0? y-1 : y;
                position--;
            }
        }
    }
}

const QVariant Joueur::getListNavire() const{
    return QVariant::fromValue(m_navires.uniqueKeys());
}

//const  Joueur::getCaseNavire(Navire* navire) const{
//    assert(m_navires.contains(navire));
//    return m_navires[navire];
//}

const QVariant Joueur::getMap() const{
    return QVariant::fromValue(m_map);
}

int Joueur::positionXNavire(Navire* navire) const{
    int case_id =m_navires[navire].case_id;
    return  m_map->getPositionXCase(case_id);
}

int Joueur::positionYNavire(Navire* navire) const{
    int case_id =m_navires[navire].case_id;
    return  m_map->getPositionYCase(case_id);
}

/**
 * @brief Joueur::recevoirAttaque
 * @param position
 * @return true si le joueur cible est mort
 */
bool Joueur::recevoirAttaque(int position, int mon_index){

    QList<QObject*> liste = m_navires.keys(Position{position,0});

    if(liste.empty()){
        m_map->modifierCouleur(position, "red");
        emit attaqueSubitRate(mon_index, m_map->numeroToPoint(position));
        Logger::getInstance()->ajouterMessage("attaque ratée ", "green");
        return false;
    }


    //touché
    if(!this->estHumain())
    m_map->modifierCouleur(position, "purple");

    Navire* navire = (Navire*) liste.at(0);
    int partie_bateau ;
    Position tmp;
    foreach (Position pos,m_navires.values(navire)) {
        if(pos.case_id == position){
            tmp = pos;
            partie_bateau = pos.bateau_partie;
            break;
        }
    }

    bool res = navire->setDurabiliteAt(partie_bateau);
    if(!res){ // partie d'un bateau détruit

        Logger::getInstance()->ajouterMessage("partie du navire " + navire->getNom() + " détruit", "Brown");

        if(!this->estHumain())
        m_map->modifierCouleur(position, "green");

        emit navirePartieDetruite(mon_index, m_map->numeroToPoint(position));
        m_navires.values(navire).removeOne(tmp);
        bool bateau_mort = navire->estDetruit();
        if(bateau_mort){
            m_navires.remove(navire);
            emit nbNavireChanged();
            bool joueur_mort = m_navires.empty();
            if(joueur_mort){
                return true;

            } else {
                Logger::getInstance()->ajouterMessage("navire " + navire->getNom() + " détruit ", "red");
            }
        }
    } else
        Logger::getInstance()->ajouterMessage("navire " + navire->getNom() + " touché, aucun dégat ", "purple");

    return false;

}


int Joueur::nbNavire(){
    return m_navires.uniqueKeys().size();
}


int Joueur::attaqueAutomatique(const QVector<QPoint>* coup_dispo, QPoint& position ){
    assert(m_strategie != nullptr);

    position  = m_strategie->cibler(coup_dispo, m_map ->getDimension());

    return m_map->getNumeroCase( position.x(), position.y());

}


void Joueur::setStrategie(QString strategie){

    StrategieAttaque* tmp = nullptr;

    if(strategie == "default")
        tmp = new Default;
    else if(strategie == "ligne")
        tmp = new Enligne;
    else if(strategie == "diagonale")
        tmp = new EnCroix;

    if(m_strategie!=nullptr)
        delete(m_strategie);
    m_strategie = tmp;
}

Joueur::~Joueur(){
    while(! m_liste.empty())
        delete(m_liste.takeFirst());

    //    if(m_strategie!=nullptr)
    //    delete(m_strategie);
}
