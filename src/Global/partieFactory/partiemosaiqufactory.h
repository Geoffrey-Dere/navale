#ifndef PARTIEMOSAIQUEABSTRACT_H
#define PARTIEMOSAIQUEABSTRACT_H

#include "partiefactory.h"
#include "../navireFactory/xvimosaique.h"
#include "../navireFactory/xxmosaique.h"


class PartieMosaiqueFactory : public PartieFactory
{
public:
    explicit PartieMosaiqueFactory();

protected :
    virtual NavireFactory* creerNavireFactory(NavireFactory::Epoque epoque);

};



#endif // PARTIEMOSAIQUEABSTRACT_H
