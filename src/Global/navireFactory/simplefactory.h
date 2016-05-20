#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include "navireFactory.h"
#include "../Navire/navire2d.h"
#include "../Navire/navire3d.h"
#include "../Navire/navire4d.h"
#include <QHash>
#include <QDateTime>

class SimpleFactory : public NavireFactory
{
public:
    SimpleFactory();

    virtual QList<Navire*> creerNavire(int nombre, int resistanceNavire);


protected :

    QHash<int,Navire* (SimpleFactory::*)(int)> m_dictionnaire;

    virtual Navire* nouveauNavire2D(int resistanceNavire) = 0;
    virtual Navire* nouveauNavire3D(int resistanceNavire) = 0;
    virtual Navire* nouveauNavire4D(int resistanceNavire) = 0;

    int m_historique = -1 ;

};

#endif // SIMPLEFACTORY_H
