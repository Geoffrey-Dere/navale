#include "xxporteavion.h"

XXPorteAvion::XXPorteAvion(int resistanceNavire) : Navire4D(resistanceNavire, getFond())
{

}


QString XXPorteAvion::getFond() const{
    if(m_horizontale)
        return ":/image/../image/PorteAvion.png";
    else
        return ":/image/../image/PorteAvionV.png";
}

QString XXPorteAvion::getNom() const{
    return "Porte Avion";
}
