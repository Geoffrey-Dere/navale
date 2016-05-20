#ifndef NAVIRE2D_H
#define NAVIRE2D_H

#include "navire.h"

class Navire2D : public Navire
{
    static const int TAILLE = 2;

public:
    Navire2D(int resistanceNavire, QString image);
    virtual QString getFond() const = 0;

};

#endif // NAVIRE2D_H
