#ifndef PARTIE_H
#define PARTIE_H

#include <QObject>
#include <assert.h>
#include <QTimer>

#include "Global/navireFactory/navireFactory.h"
#include "joueur.h"
#include "logger.h"

class Partie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int temps READ temps NOTIFY tempsChanged)
    Q_PROPERTY(QString joueurCourant READ joueurCourant  NOTIFY joueurCourantChanged)
public:
    explicit Partie(QObject *parent = 0);
    ~Partie();

    void addJoueurs(Joueur* j1, Joueur* j2);
    void setNavireFactory(NavireFactory* f);

    /**
     * @brief preparation
     * @param placement false placement automatique, true choix du joueur
     */
    void preparation(QPoint dimension, QString s, bool placement,  int nb_navire);

    Q_INVOKABLE void attaquer(int index_joueur , int position);
    Q_INVOKABLE int nombreJoueur();
    Q_INVOKABLE QVariant getNextJoueurAPlacer();
    Q_INVOKABLE void lancer();

    void setStrategie(QString s);

signals:
    void commencer(bool placement,  int nb_navire = 0 );
    void fin(QString joueur);
    void tempsChanged();
    void joueurCourantChanged();

public slots :
    QVariant const getJoueur(int i) const ;
 private slots :
    void attaqueAutomatique();
    void diminuerTailleCoup(int position_joueur,  QPoint pos); // reduit m_coup si un bout de navire est détruit

    void compteARembours();
    int temps();
    QString joueurCourant();

private:    
    void rebootTimer();


    QList<Joueur*> m_liste_joueur ;
    NavireFactory* m_navireFactory = nullptr;
    int m_courantJoueur = 0 ;
    bool m_tour_humain = true;
    QTimer m_timer ; // temps max du joueur

    QTimer m_car ; // compte a rebours
    int m_temps = 0; // du compte a rebours


    /**
      * @brief m_coup
      * Coup qui sont disponibles contre chaque joueur
      * Utiliser pour les attaques automatiques
      * Donc si le nombre de joueurs est >2, tout le monde sait les positions attaquées entre d'autres joueurs
      */
    QVector <QVector<QPoint>* > *m_coups = nullptr;

    const int tempsTourJoueur = 25 ; // temps tour d'un joueur (seconde)
    const int tempsTourMachine = 1;
};

#endif // PARTIE_H
