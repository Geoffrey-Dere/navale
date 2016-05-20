#include "partiefactory.h"

PartieFactory::PartieFactory(QObject *parent) : QObject(parent)
{
}

Partie* PartieFactory::creerPartie(NavireFactory::Epoque epoque,  int nb_navire, Niveau* niveau){

    Partie* partie = new Partie();

    NavireFactory* navireFactory = creerNavireFactory(epoque);
    Joueur* joueur = new Joueur("joueur", navireFactory, nb_navire, niveau->resistanceNavireJoueur());
    Joueur* ordi = new Joueur("machine1", navireFactory, nb_navire, niveau->resistanceNavireOrdi(), false);
    partie->addJoueurs(joueur , ordi);

    return partie;

}


PartieFactory::~PartieFactory(){

    QHash<NavireFactory::Epoque,NavireFactory*>::const_iterator i;
    for (i = m_dictionnaire.constBegin(); i != m_dictionnaire.constEnd(); ++i)
        delete(i.value());

}
