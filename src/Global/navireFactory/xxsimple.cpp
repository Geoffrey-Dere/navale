#include "xxsimple.h"

XXSimple::XXSimple() : SimpleFactory()
{

}


Navire* XXSimple::nouveauNavire2D(int resistanceNavire ){
    return new XXPatrouilleur(resistanceNavire);
}

Navire* XXSimple::nouveauNavire3D(int resistanceNavire){
    return new XXCroiseur(resistanceNavire) ;
}

Navire* XXSimple::nouveauNavire4D(int resistanceNavire){
    return new XXPorteAvion(resistanceNavire) ;
}
