#include "xvichebec.h"

XVIChebec::XVIChebec(int resistanceNavire) : Navire2D(resistanceNavire, getFond())
{

}

QString XVIChebec::getFond() const{
    if(m_horizontale)
        return ":/image/../image/Chebec.png";
    else
        return ":/image/../image/ChebecV.png";
}

QString XVIChebec::getNom() const{
    return "Chebec";
}
