#include "facile.h"

Facile::Facile(QObject *parent) : Niveau("Facile", parent)
{

}

int Facile::resistanceNavireOrdi(){
    return 1;
}

int Facile::resistanceNavireJoueur(){
    return 2;
}
