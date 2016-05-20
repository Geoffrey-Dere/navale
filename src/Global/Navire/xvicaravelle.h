#ifndef XVICARAVELLE_H
#define XVICARAVELLE_H

#include "navire3d.h"

class XVICaravelle : public Navire3D
{
    Q_OBJECT
public:
    explicit XVICaravelle(int resistanceNavire);
    virtual QString getFond() const;
    virtual QString getNom() const;
};

#endif // XVICARAVELLE_H
