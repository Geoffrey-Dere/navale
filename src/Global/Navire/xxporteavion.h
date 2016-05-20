#ifndef XXPORTEAVION_H
#define XXPORTEAVION_H

#include "navire4d.h"

class XXPorteAvion : public Navire4D
{
    Q_OBJECT
public:
    explicit XXPorteAvion(int resistanceNavire);
    virtual QString getFond() const;
       virtual QString getNom() const;



};

#endif // XXPORTEAVION_H
