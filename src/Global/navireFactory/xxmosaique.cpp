#include "xxmosaique.h"


XXMosaique::XXMosaique(QObject *parent) : FactoryMosaique(parent)
{
}


Navire2D* XXMosaique::nouveauNavire2D(int resistanceNavire){
    return new XXPatrouilleur(resistanceNavire);
}

Navire3D* XXMosaique::nouveauNavire3D(int resistanceNavire){
    return new XXCroiseur(resistanceNavire) ;
}

Navire4D* XXMosaique::nouveauNavire4D(int resistanceNavire){
    return new XXPorteAvion(resistanceNavire) ;
}

