#ifndef XXMOSAIQUE_H
#define XXMOSAIQUE_H

#include "factorymosaique.h"
#include "../Navire/xxporteavion.h"
#include "../Navire/xxcroiseur.h"
#include "../Navire/xxpatrouilleur.h"

class XXMosaique : public FactoryMosaique
{

public :
    XXMosaique(QObject *parent = 0);

    virtual Navire2D* nouveauNavire2D(int resistanceNavire);
    virtual Navire3D* nouveauNavire3D(int resistanceNavire);
    virtual Navire4D* nouveauNavire4D(int resistanceNavire);

};

#endif // XXMOSAIQUE_H
