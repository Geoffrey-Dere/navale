#include "simplefactory.h"

SimpleFactory::SimpleFactory() : NavireFactory()
{
    m_dictionnaire.insert(2, &SimpleFactory::nouveauNavire2D);
    m_dictionnaire.insert(3, &SimpleFactory::nouveauNavire3D);
    m_dictionnaire.insert(4, &SimpleFactory::nouveauNavire4D);

}

QList<Navire*> SimpleFactory::creerNavire(int nombre, int resistanceNavire){

    // choix aléatoire du bateau
    qsrand(QTime::currentTime().msec());
    int nb = qrand()%(4-2 + 1) + 2; // nombre entrre 2 et 4

    if(m_historique==-1){
        m_historique = nb;
    } else{
        nb = m_historique;
        m_historique = -1 ;
    }


    QList<Navire*> liste;

    for(int i = 0; i < nombre ; i++)
        liste.append( (this->*m_dictionnaire[nb])(resistanceNavire) );

    return liste;

}
