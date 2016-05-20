#ifndef PARTIESIMPLEFACTORY_H
#define PARTIESIMPLEFACTORY_H


#include "partiefactory.h"
#include "../navireFactory/xvisimple.h"
#include "../navireFactory/xxsimple.h"

class PartieSimpleFactory : public PartieFactory
{
public:
    PartieSimpleFactory();

protected:
     virtual NavireFactory* creerNavireFactory(NavireFactory::Epoque epoque);
};

#endif // PARTIESIMPLEFACTORY_H
