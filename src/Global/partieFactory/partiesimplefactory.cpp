#include "partiesimplefactory.h"

PartieSimpleFactory::PartieSimpleFactory() : PartieFactory()
{
   m_dictionnaire.insert(NavireFactory::Epoque::XX,  new XXSimple());
   m_dictionnaire.insert(NavireFactory::Epoque::XVI,  new XVISimple());
}

NavireFactory* PartieSimpleFactory::creerNavireFactory(NavireFactory::Epoque epoque){

    if(m_dictionnaire.contains(epoque))
        return m_dictionnaire[epoque];

    return nullptr;
}
