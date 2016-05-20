#include "moyen.h"

Moyen::Moyen(QObject *parent) : Niveau("Moyen", parent)
{

}
int Moyen::resistanceNavireOrdi(){
    return 2;
}

int Moyen::resistanceNavireJoueur(){
    return 2;
}
