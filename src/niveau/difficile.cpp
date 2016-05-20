#include "difficile.h"

Difficile::Difficile(QObject *parent) : Niveau("Difficile", parent)
{

}

int Difficile::resistanceNavireOrdi(){
    return 3;
}

int Difficile::resistanceNavireJoueur(){
    return 1;
}
