#ifndef PARTIEFACTORY_H
#define PARTIEFACTORY_H

#include <QObject>
#include <QHash>

#include "../partie.h"
#include "../joueur.h"
#include "../navireFactory/navireFactory.h"
#include "niveau/niveau.h"

class PartieFactory : public QObject
{
    Q_OBJECT
public:
    explicit PartieFactory(QObject *parent = 0);
    virtual ~PartieFactory();

    Partie* creerPartie(NavireFactory::Epoque epoque,  int nb_navire, Niveau* niveau );

protected :

    virtual NavireFactory* creerNavireFactory(NavireFactory::Epoque epoque) = 0;

    QHash<NavireFactory::Epoque,NavireFactory*> m_dictionnaire;
};

#endif // PARTIEFACTORY_H
