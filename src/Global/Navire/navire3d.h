#ifndef NAVIRE3D_H
#define NAVIRE3D_H

#include "navire.h"

class Navire3D : public Navire
{
    static const int TAILLE = 3;

public:
    Navire3D(int resistanceNavire, QString image);
    virtual QString getFond() const = 0;
};

#endif // NAVIRE3D_H
