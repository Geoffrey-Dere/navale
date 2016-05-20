#ifndef XVICHEBEC_H
#define XVICHEBEC_H

#include "navire2d.h"

class XVIChebec : public Navire2D
{
    Q_OBJECT
public:
    explicit XVIChebec(int resistanceNavire);
      virtual QString getFond() const;
       virtual QString getNom() const;
};

#endif // XVICHEBEC_H
