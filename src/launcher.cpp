#include "launcher.h"

Launcher::Launcher(QQmlApplicationEngine* engine, QObject *parent) : QObject(parent)
{
    m_listeNiveau.append(new Facile(this));
    m_listeNiveau.append(new Moyen(this));
    m_listeNiveau.append(new Difficile(this));

    m_engine = engine;
}

// pour l'affichage des niveaux
QVariant Launcher::niveau(){
    return QVariant::fromValue(m_listeNiveau);
}

int Launcher::index_niveau(){
    return m_index_niveau;
}

void Launcher::setIndex_niveau(int i){
    assert(i>=0 && i <m_listeNiveau.size());
    m_index_niveau = i ;
    emit niveauChanged();
}

//retourne la liste des époques possibles pour l'affichage
const QStringList Launcher::getListeMode()const{
    return NavireFactory::getListType();

}

int Launcher::mode(){
    return (int)m_mode;

}

const QStringList Launcher::getListeEpoque() const{
    return NavireFactory::getListEpoque();

}

void Launcher::setMode(QString mode){
    m_mode = NavireFactory::StringtoType(mode);
}


int  Launcher::epoque(){
    return (int) m_epoque;

}

void  Launcher::setEpoque(QString epoque){
    m_epoque = NavireFactory::EpoqueStringtoType(epoque);
}


bool Launcher::placement(){
    return m_placement;
}

void Launcher::setPlacement(bool b){
    if(m_placement != b){
        m_placement = b ;
        emit placementChanged();
    }
}

void Launcher::start(){

    PartieFactory* p = nullptr;

    if(m_mode == NavireFactory::Type::MOSAIQUE)
        p = new PartieMosaiqueFactory();
    else if(m_mode == NavireFactory::Type::SIMPLE)
        p = new PartieSimpleFactory();

    //m_engine->rootContext()->setContextProperty("mapModel",  m_map);
    Niveau* niveau = (Niveau*) m_listeNiveau.at(m_index_niveau);

    if(p!=nullptr){
        partie = p->creerPartie(m_epoque, m_nbNavire, niveau);
        m_engine->rootContext()->setContextProperty("partie",  partie); //qml connait l'instance partie
        emit partieChanged();

        partie->preparation(m_dimensions, m_strategie, m_placement, m_nbNavire);


    }

    delete p;

}

void Launcher::setStrategie(QString s){


    if(m_strategie==s)
        return;

    m_strategie = s;

    if(partie !=nullptr)
        partie->setStrategie(s);

    emit strategieChanged();
}


QString Launcher::strategie(){
    return m_strategie;
}

void Launcher::setNombre_navire(int i){
    m_nbNavire = i;
}

int Launcher::nombre_navire(){
    return m_nbNavire;
}

Launcher::~Launcher(){

    if(partie)
    delete(partie);
    // pas besoin de delete map et les Niveaux, Comme launcher est leur père, quand launcher est détruit, Qt détruit ses "fils"
}

