#include "xvigalion.h"

XVIGalion::XVIGalion(int resistanceNavire) : Navire4D(resistanceNavire, getFond())
{

}


QString XVIGalion::getFond() const{
    if(m_horizontale)
        return ":/image/../image/Galion.png";
    else
        return ":/image/../image/GalionV.png";
}

QString XVIGalion::getNom() const{
    return "Galion";
}
