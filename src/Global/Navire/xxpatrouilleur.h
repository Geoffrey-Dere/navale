#ifndef XXPATROUILLEUR_H
#define XXPATROUILLEUR_H

#include "navire2d.h"

class XXPatrouilleur : public Navire2D
{
     Q_OBJECT
public:
    explicit XXPatrouilleur(int resistanceNavire);
      virtual QString getFond() const;
       virtual QString getNom() const;
    ~XXPatrouilleur();


};

#endif // XXPATROUILLEUR_H
