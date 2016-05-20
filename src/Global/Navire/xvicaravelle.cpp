#include "xvicaravelle.h"

XVICaravelle::XVICaravelle(int resistanceNavire) : Navire3D(resistanceNavire , getFond())
{

}

QString XVICaravelle::getFond() const{
    if(m_horizontale)
        return ":/image/../image/Caravelle.png";
    else
        return ":/image/../image/CaravelleV.png";
}

QString XVICaravelle::getNom() const{
    return "Caravelle";
}
