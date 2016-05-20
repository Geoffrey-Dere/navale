#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QObject>
#include <QVariant>
#include <assert.h>
#include <QDebug>
#include"QQmlApplicationEngine"
#include <QQmlContext>
#include <QPoint>

#include "Global/partie.h"
#include "Global/navireFactory/navireFactory.h"
#include "Global/partieFactory/partiemosaiqufactory.h"
#include "Global/partieFactory/partiesimplefactory.h"
#include "Map/map.h"
#include "strategie/enligne.h"
#include "strategie/encroix.h"
#include "niveau/niveau.h"
#include "niveau/facile.h"
#include "niveau/moyen.h"
#include "niveau/difficile.h"


class Launcher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant niveau READ niveau CONSTANT)
    Q_PROPERTY(int index_niveau READ index_niveau WRITE setIndex_niveau NOTIFY niveauChanged)
    Q_PROPERTY(bool placement READ placement WRITE setPlacement NOTIFY placementChanged)
    Q_PROPERTY(QString strategie READ strategie WRITE setStrategie NOTIFY strategieChanged)
    Q_PROPERTY(int nombre_navire READ nombre_navire WRITE setNombre_navire NOTIFY nombre_navireChanged)

public:
    explicit Launcher(QQmlApplicationEngine* engine, QObject *parent = 0);
    ~Launcher();


signals:
    void niveauChanged();
    void placementChanged();
    void partieChanged();
    void strategieChanged();
    void nombre_navireChanged();

public slots:
    QVariant niveau();
    int index_niveau();
    void setIndex_niveau(int i);
    int mode();
    void setMode(QString mode);
    int epoque();
    void setEpoque(QString epoque);
    bool placement();
    void setPlacement(bool b);
    int nombre_navire();

    Q_INVOKABLE const QStringList getListeMode() const;
    Q_INVOKABLE const QStringList getListeEpoque() const ;

    // fonction appeler quand le joueur clique sur "commencer"
    Q_INVOKABLE void start();

protected :
    void setStrategie(QString s);
    QString strategie();
    void setNombre_navire(int i); // utilisable only par qml


    QList<QObject*> m_listeNiveau ;
    int m_index_niveau = 0; // index du niveau courant
    Partie* partie = nullptr;
    NavireFactory::Type m_mode ; // normal, mosaique
    NavireFactory::Epoque m_epoque = NavireFactory::Epoque::XX;
    int m_nbNavire = 3;
    QString m_strategie  = "default";
    bool m_placement = false ; // true si le joueur doit choisir son placement
    QQmlApplicationEngine *m_engine;

    QPoint m_dimensions = QPoint(10,10);
    Map * m_map = nullptr;

};

#endif // LAUNCHER_H
