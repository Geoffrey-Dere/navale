#include "niveau.h"

Niveau::Niveau(QString nom, QObject *parent)
    : QObject(parent), m_nom(nom)
{

}

QString Niveau::getNom(){
    return  m_nom;
}


 QString Niveau::afficher(){

     return QString("résistance de vos bateaux : %1 \n"
                    "réstitance des bateaux de l'ordinateur : %2")
             .arg(resistanceNavireJoueur()).arg(resistanceNavireOrdi());
 }
