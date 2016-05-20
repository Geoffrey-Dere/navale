#ifndef FACILE_H
#define FACILE_H

#include <QObject>
#include "niveau.h"

class Facile : public Niveau
{
    Q_OBJECT
public:
    explicit Facile(QObject *parent = 0);
    virtual int resistanceNavireOrdi();
    virtual int resistanceNavireJoueur();

signals:

public slots:
};

#endif // FACILE_H
