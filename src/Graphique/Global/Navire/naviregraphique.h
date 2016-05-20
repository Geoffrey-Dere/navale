#ifndef NAVIREGRAPHIQUE_H
#define NAVIREGRAPHIQUE_H


#include <QQuickPaintedItem>
#include <QPainter>
#include <QDebug>
#include <assert.h>
#include <QString>
#include <QFileInfo>
#include <QColor>

#include "Global/Navire/navire.h"

class NavireGraphique : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(Navire* modele READ modele WRITE setModele NOTIFY modeleChanged)
public:
    NavireGraphique(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:
    void modeleChanged();

public slots :

    Navire* modele();
    void setModele(Navire* navire);

protected:
    void dessinerCroix(QPainter * painter, int x, int y, int w, int h);

    Navire* m_navire;
};
#endif // NAVIREGRAPHIQUE_H
