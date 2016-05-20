#ifndef XXSIMPLE_H
#define XXSIMPLE_H

#include "simplefactory.h"
#include "../Navire/xxporteavion.h"
#include "../Navire/xxcroiseur.h"
#include "../Navire/xxpatrouilleur.h"

class XXSimple : public SimpleFactory
{
public:
    XXSimple();

protected:
    virtual Navire* nouveauNavire2D(int resistanceNavire);
    virtual Navire* nouveauNavire3D(int resistanceNavire);
    virtual Navire* nouveauNavire4D(int resistanceNavire);
};

#endif // XXSIMPLE_H
