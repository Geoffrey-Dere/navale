#ifndef CASE_H
#define CASE_H


#include <QQuickPaintedItem>
#include <QPainter>
#include <QDebug>
#include <assert.h>

class CaseGraphique : public QQuickPaintedItem
{

    Q_OBJECT
    Q_PROPERTY(QString couleur READ couleur WRITE setCouleur NOTIFY couleurChanged)

public:
    CaseGraphique(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:
    void couleurChanged();

public slots :
    inline QString couleur(){ return m_couleur.name();}
    void setCouleur(const QString& c);

protected:
    QColor m_couleur ;
};

#endif // CASE_H
