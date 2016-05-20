#include "partie.h"

Partie::Partie(QObject *parent) : QObject(parent)
{
    connect(&m_timer,SIGNAL(timeout()), this, SLOT(attaqueAutomatique()));
    connect(&m_car,SIGNAL(timeout()), this, SLOT(compteARembours()));

    m_car.setInterval(1000);
    m_car.stop();
}


void Partie::addJoueurs(Joueur* j1, Joueur* j2){

    assert(j1->estHumain());
    assert(!j2->estHumain());

    m_liste_joueur.append(j1);
    m_liste_joueur.append(j2);

}

void Partie::setNavireFactory(NavireFactory* f){
    delete(m_navireFactory);
    m_navireFactory = f;
}

/**
 * @brief Partie::start
 * @param placement true : le joueur choisit sa place, false sinon
 */
void Partie::preparation(QPoint dimension, QString strategie , bool placement,  int nb_navire){

    qsrand(QTime::currentTime().msec());

    // int nb_joueur = m_liste_joueur.size();

    for(Joueur* joueur : m_liste_joueur){

        joueur->creerMap(dimension);

        if(!placement && joueur->estHumain())
            joueur->placementAutomatique();

        if(!joueur->estHumain())
            joueur->placementAutomatique();


        if(joueur->estHumain())
            joueur->setStrategie("default");
        else
            joueur->setStrategie(strategie);


        connect(joueur, SIGNAL(navirePartieDetruite(int,QPoint)), this, SLOT(diminuerTailleCoup(int,QPoint)));
        connect(joueur, SIGNAL(attaqueSubitRate(int,QPoint)), this, SLOT(diminuerTailleCoup(int,QPoint)));
    }

    m_coups = new QVector<QVector<QPoint>* >();

    for(int i = 0 ; i < 2 ; i++){

        m_coups->append(new QVector<QPoint>());

        for(int x = 0  ; x < dimension.x() ; x++ )
            for(int y = 0  ; y < dimension.y() ; y++ )
                m_coups->at(i)->append(QPoint(x,y));
    }


    Logger::getInstance()->clean();
    emit commencer(placement, nb_navire);
}



QVariant const Partie::getJoueur(int i) const{
    assert(i>=0 && i <m_liste_joueur.size());
    return QVariant::fromValue(m_liste_joueur.at(i));
}



/**
 * @brief Partie::attaquer
 * @param index_joueur numero de position dans la liste des joueurs (joueur qui est attaqué)
 * @param position case
 */
void Partie::attaquer(int index_joueur, int position){
    assert(index_joueur>=0 && index_joueur< m_liste_joueur.size());

    Joueur* attaquant = m_liste_joueur.at(m_courantJoueur);
    Joueur* cible = m_liste_joueur.at(index_joueur);

    if(attaquant == cible) {
        return ;
    }

    if(attaquant->estHumain() != m_tour_humain){
        return ;
    }

    if(m_timer.isActive() && !m_tour_humain){
        return ;
    }
    m_timer.stop();
    m_car.stop();

    Logger::getInstance()->ajouterMessage(QString(attaquant->identifiant() +  " attaque " + cible->identifiant() +
                                                  "sur la case %1" ).arg(position));

    bool estMort = cible->recevoirAttaque(position, index_joueur);
    if(estMort){
        m_liste_joueur.removeAt(index_joueur);
    }

    if(m_liste_joueur.size()==1)
        emit fin(m_liste_joueur.at(0)->identifiant());
    else{
        m_courantJoueur++;
        m_courantJoueur%=m_liste_joueur.size();
        m_tour_humain = m_liste_joueur.at(m_courantJoueur)->estHumain();
        rebootTimer();
        emit joueurCourantChanged();

         Logger::getInstance()->ajouterMessage("******");
        Logger::getInstance()->ajouterMessage("C'est au tour de" + m_liste_joueur.at(m_courantJoueur)->identifiant());

    }

}

void Partie::attaqueAutomatique(){

    m_timer.stop();
    m_car.stop();

    int joueur_cible = (qrand() % m_liste_joueur.size());

    if(m_courantJoueur == joueur_cible){
        joueur_cible++ ;
        joueur_cible %= m_liste_joueur.size();
    }

    QPoint position;
    int id_case = m_liste_joueur.at(m_courantJoueur)->attaqueAutomatique(m_coups->value(joueur_cible), position);

    attaquer(joueur_cible, id_case);
}


void Partie::diminuerTailleCoup(int position_joueur,  QPoint pos){
 m_coups->value(position_joueur)->removeOne(pos);
}

QVariant Partie::getNextJoueurAPlacer(){

    Joueur* joueur = nullptr;
    int i = 0;

    while (joueur==nullptr && i < m_liste_joueur.size()){
        if(m_liste_joueur.at(i)->estHumain())
            joueur = m_liste_joueur.at(i);
        i++;
    }

    assert(joueur!=nullptr);
    return QVariant::fromValue(joueur);

}    

void Partie::rebootTimer(){

    if(m_liste_joueur.at(m_courantJoueur)->estHumain()){
        m_timer.setInterval(tempsTourJoueur*1000);
         m_temps = tempsTourJoueur;
     }
     else{
         m_timer.setInterval(tempsTourMachine*1000);
         m_temps = tempsTourMachine;
     }

     m_timer.start();
     m_car.start();
 }

 void Partie::compteARembours(){

     m_temps--;
     m_car.start();
     emit tempsChanged();
 }


 int Partie::nombreJoueur(){
     return m_liste_joueur.size();
 }

 void Partie::lancer(){
     rebootTimer();
     Logger::getInstance()->ajouterMessage("******");
     Logger::getInstance()->ajouterMessage("C'est au tour de" + m_liste_joueur.at(m_courantJoueur)->identifiant());
 }

 void Partie::setStrategie(QString s){

     for(int i = 0 ; i < m_liste_joueur.size() ; i++){
         if(!m_liste_joueur.value(i)->estHumain())
             m_liste_joueur.value(i)->setStrategie(s);
     }
 }

 int Partie::temps(){
     return m_temps;
 }

 QString Partie::joueurCourant(){
     return m_liste_joueur.at(m_courantJoueur)->identifiant();
 }


 Partie::~Partie(){
     m_timer.stop();

    delete(m_navireFactory);

    while(! m_liste_joueur.isEmpty()){
        delete(m_liste_joueur.takeFirst());
    }

    for(int i = 0 ; i < m_coups->size(); i++){
        delete(m_coups->value(i));
}
    delete(m_coups);

}
