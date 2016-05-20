#ifndef XVISIMPLE_H
#define XVISIMPLE_H

#include "simplefactory.h"
#include "../Navire/xvicaravelle.h"
#include "../Navire/xvichebec.h"
#include "../Navire/xvigalion.h"

class XVISimple : public SimpleFactory
{
public:
    XVISimple();

protected:
    virtual Navire* nouveauNavire2D(int resistanceNavire);
    virtual Navire* nouveauNavire3D(int resistanceNavire);
    virtual Navire* nouveauNavire4D(int resistanceNavire);
};

#endif // XVISIMPLE_H
