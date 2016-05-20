#ifndef FACTORYMOSAIQUE_H
#define FACTORYMOSAIQUE_H

#include "navireFactory.h"
#include "../Navire/navire2d.h"
#include "../Navire/navire3d.h"
#include "../Navire/navire4d.h"

class FactoryMosaique : public NavireFactory
{
    Q_OBJECT
public:
    explicit FactoryMosaique(QObject *parent = 0);
    //static FactoryMosaique* getFactory(int periode);

    virtual QList<Navire*>  creerNavire(int nombre, int resistanceNavire);
    virtual Navire2D* nouveauNavire2D(int resistanceNavire) = 0;
    virtual Navire3D* nouveauNavire3D(int resistanceNavire) = 0;
    virtual Navire4D* nouveauNavire4D(int resistanceNavire) = 0;
};

#endif // FACTORYMOSAIQUE_H
