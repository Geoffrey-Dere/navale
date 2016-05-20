#ifndef XVIMOSAIQUE_H
#define XVIMOSAIQUE_H

#include <QObject>
#include "factorymosaique.h"
#include "../Navire/xvicaravelle.h"
#include "../Navire/xvichebec.h"
#include "../Navire/xvigalion.h"

class XVIMosaique  : public FactoryMosaique
{

public :
    XVIMosaique(QObject* parent = 0);

    static XVIMosaique* getInstance();
    virtual Navire2D* nouveauNavire2D(int resistanceNavire);
    virtual Navire3D* nouveauNavire3D(int resistanceNavire);
    virtual Navire4D* nouveauNavire4D(int resistanceNavire);

};

#endif // XVIMOSAIQUE_H
