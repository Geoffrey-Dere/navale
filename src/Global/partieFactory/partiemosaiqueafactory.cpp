#include "partiemosaiqufactory.h"

PartieMosaiqueFactory::PartieMosaiqueFactory() : PartieFactory()
{
    m_dictionnaire.insert(NavireFactory::Epoque::XX,  new XXMosaique());
    m_dictionnaire.insert(NavireFactory::Epoque::XVI,  new XVIMosaique());
}

NavireFactory* PartieMosaiqueFactory::creerNavireFactory(NavireFactory::Epoque epoque){

    if(m_dictionnaire.contains(epoque))
        return m_dictionnaire[epoque];

    return nullptr;
}
