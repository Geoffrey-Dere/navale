#ifndef NAVIRE4D_H
#define NAVIRE4D_H

#include "navire.h"

class Navire4D : public Navire
{
    static const int TAILLE = 4;

public:
    Navire4D(int resistanceNavire, QString image);
    virtual QString getFond() const = 0;
};

#endif // NAVIRE4D_H
