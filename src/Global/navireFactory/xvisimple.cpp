#include "xvisimple.h"

XVISimple::XVISimple() : SimpleFactory()
{

}


Navire* XVISimple::nouveauNavire2D(int resistanceNavire ){
    return new XVIChebec(resistanceNavire);
}

Navire* XVISimple::nouveauNavire3D(int resistanceNavire){
    return new XVICaravelle(resistanceNavire) ;
}

Navire* XVISimple::nouveauNavire4D(int resistanceNavire){
    return new XVIGalion(resistanceNavire) ;
}
