#include "xxcroiseur.h"

XXCroiseur::XXCroiseur(int resistanceNavire) : Navire3D(resistanceNavire, getFond())
{

}


QString XXCroiseur::getFond() const{
    if(m_horizontale)
        return ":/image/../image/Croiseur.png";
    else
        return ":/image/../image/CroiseurV.png";
}

QString XXCroiseur::getNom() const{
    return "Croiseur";
}
