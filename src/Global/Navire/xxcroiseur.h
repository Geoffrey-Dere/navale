#ifndef XXCROISEUR_H
#define XXCROISEUR_H

#include "navire3d.h"
class XXCroiseur : public Navire3D
{
    Q_OBJECT
public:
    explicit XXCroiseur(int resistanceNavire);
      virtual QString getFond() const;
       virtual QString getNom() const;

signals:

public slots:
};

#endif // XXCROISEUR_H
