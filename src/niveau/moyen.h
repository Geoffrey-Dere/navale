#ifndef MOYEN_H
#define MOYEN_H

#include <QObject>
#include "niveau.h"

class Moyen : public Niveau
{
    Q_OBJECT
public:
    explicit Moyen(QObject *parent = 0);
    virtual int resistanceNavireOrdi();
    virtual int resistanceNavireJoueur();

signals:

public slots:
};

#endif // MOYEN_H
