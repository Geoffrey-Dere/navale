#ifndef DIFFICILE_H
#define DIFFICILE_H

#include "niveau.h"

class Difficile : public Niveau
{
public:
    Difficile(QObject* parent);
    virtual int resistanceNavireOrdi();
    virtual int resistanceNavireJoueur();
};

#endif // DIFFICILE_H
