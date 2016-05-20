#ifndef XVIGALION_H
#define XVIGALION_H

#include "navire4d.h"

class XVIGalion : public Navire4D
{
    Q_OBJECT
public:
    explicit XVIGalion(int resistanceNavire);
      virtual QString getFond() const;
       virtual QString getNom() const;
};

#endif // XVIGALION_H
