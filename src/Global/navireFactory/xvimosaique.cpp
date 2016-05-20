#include "xvimosaique.h"



XVIMosaique::XVIMosaique(QObject *parent) : FactoryMosaique(parent)
{

}

Navire2D* XVIMosaique::nouveauNavire2D(int resistanceNavire){
    return new XVIChebec(resistanceNavire);
}

Navire3D* XVIMosaique::nouveauNavire3D(int resistanceNavire){
    return new XVICaravelle(resistanceNavire);
}

Navire4D* XVIMosaique::nouveauNavire4D(int resistanceNavire){
    return new XVIGalion(resistanceNavire);
}
