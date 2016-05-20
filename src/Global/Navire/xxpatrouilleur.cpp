#include "xxpatrouilleur.h"

XXPatrouilleur::XXPatrouilleur(int resistanceNavire) : Navire2D(resistanceNavire , getFond())
{

}

 XXPatrouilleur::~XXPatrouilleur(){

 }

 QString XXPatrouilleur::getFond() const{
     if(m_horizontale)
         return ":/image/../image/Patrouilleur.png";
     else
         return ":/image/../image/PatrouilleurV.png";
 }

 QString XXPatrouilleur::getNom() const{
     return "Patrouilleur";
 }
