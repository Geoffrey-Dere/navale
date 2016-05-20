#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include <QHash>
#include <QDebug>
#include <QPoint>
#include <QDateTime>

#include "strategie/strategieattaque.h"
#include "navireFactory/navireFactory.h"
#include "Map/map.h"
#include "strategie/default.h"
#include "strategie/encroix.h"
#include "strategie/enligne.h"
#include "Global/logger.h"

class Joueur : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariant map READ getMap CONSTANT)
    Q_PROPERTY(int nbNavire READ nbNavire NOTIFY nbNavireChanged)
    Q_PROPERTY(QString identifiant READ identifiant CONSTANT)

public:
    explicit Joueur(QString identifiant, NavireFactory* navireFactory, int nb_navire, int resistanceNavire,
                    bool humain = true, QObject *parent = 0);
    ~Joueur();

    /**
      * @brief addCase ajoute le navire avec ses cases associées dans la collection des navires du joueur
      * @return true si le navire a bien été ajouté
      */
    bool addCase(Navire* navire,QList<int>& cases);

    void placementAutomatique();

   // const int getCaseNavire(Navire* navire) const;

    void creerMap(QPoint dimension);

    bool recevoirAttaque(int position, int mon_index);

    int attaqueAutomatique(const QVector<QPoint>* coup, QPoint& position);

    void setStrategie(QString strategie);

    inline operator QString() const {
     {
         return m_identifiant;
     }

 }
    QString identifiant();

signals:
    void nbNavireChanged();
    void navirePartieDetruite(int position, QPoint pos);
     void attaqueSubitRate(int position, QPoint pos);

public slots:
    Q_INVOKABLE QVariant getNextNavireAPlacer() ;
    const QVariant getListNavire() const;
    Q_INVOKABLE bool estHumain();
    int positionXNavire(Navire* navire) const;
    int positionYNavire(Navire* navire) const;
    void placerNavire(Navire* navire,QList<int> cases,bool horizontale);
    int nbNavire();

protected :

    const QVariant getMap() const ;

    struct Position{
        int case_id;
        int bateau_partie;

        inline  bool operator==(const Position& a) const {
           if (a.case_id==case_id)
              return true;
           else
              return false;
        }
       inline operator QString() const {
        {
            return QString("(%1 , %2 )").arg(case_id).arg(bateau_partie);
        }

    }
    };

     QHash<QObject*, Position> m_navires ; // contient les navires posés et leurs positions

    StrategieAttaque* m_strategie = nullptr ;
    QList<Navire*> m_liste; // liste temporaire qui contient les navires non placé

    bool m_humain ; // true si humain
    Map* m_map = nullptr;
    QString m_identifiant; // ~pseudo

};

#endif // JOUEUR_H
