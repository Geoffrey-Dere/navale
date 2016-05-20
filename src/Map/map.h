#ifndef MAP_H
#define MAP_H


#include <QDebug>
#include <assert.h>
#include <QObject>
#include <QVariant>
#include <QPoint>
#include <QAbstractListModel>
#include <QPoint>
#include "caseMap.h"

class Map : public QAbstractListModel
{
    Q_OBJECT

public:

    explicit Map(QPoint dimension, QObject *parent = 0);
    //modele
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void appendRow(ListItem* item);
    void appendRows(const QList<ListItem*> &items);
    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QModelIndex indexFromRow( const int row ) const;
    QModelIndex indexFromItem(const ListItem *item) const;

    const QPoint getDimension() const;
    int getNumeroCase(int x,int y) const;
    QPoint numeroToPoint(int row) const;

    int getPositionXCase(const int row) const;
    int getPositionYCase(const int row) const;

    ~Map();

public slots :
    Q_INVOKABLE int tailleCase(int width, int height);
    Q_INVOKABLE void modifierCouleur(const int row, const QString &couleur);
    Q_INVOKABLE void modifierPositionCase(const int row, int x, int y);
    void handleItemChange();

protected :
    int m_nombreCaseX = 10;
    int m_nombreCaseY = 10;

    ListItem* m_prototype;
    QList<ListItem*> m_list;

};

#endif // MAP_H
