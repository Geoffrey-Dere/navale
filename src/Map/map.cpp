#include "map.h"

Map::Map(QPoint dimension, QObject *parent)
    :  QAbstractListModel(parent)
{

    m_prototype = new CaseMap();
    m_nombreCaseX = dimension.x();
    m_nombreCaseY = dimension.y();

    QString couleur1("#454795") ;
    QString couleur2("#7F81C5");

    int i = 0;
    int v = 1;
    int compteur = 0;
    for(int j = 0; j < m_nombreCaseY ; j++){
        v = qAbs(v-1);
        for(i = v ; i < m_nombreCaseX+v; i++){

            if (i%2==0)
                appendRow(new CaseMap(compteur++, couleur1, this));
            else
                appendRow(new CaseMap(compteur++, couleur2, this));

        }
    }
}


int Map::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();
    return m_list.at(index.row())->data(role);
}


/* ajouter données dans le modèle */
void Map::appendRow(ListItem *item)
{
    appendRows(QList<ListItem*>() << item);
}

void Map::appendRows(const QList<ListItem *> &items)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount()+items.size()-1);
    foreach(ListItem *item, items) {
        connect(item, SIGNAL(dataChanged()), SLOT(handleItemChange()));
        m_list.append(item);
    }
    ;
    endInsertRows();
}
/*****************************/




/* modifier données dans le modèle */
Qt::ItemFlags Map::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}


bool Map::setData(const QModelIndex &index,
                  const QVariant &value, int role)
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return false;

    return m_list.at(index.row())->setData(value, role);
}


QModelIndex Map::indexFromRow( const int row ) const
{
    return index(row);
}



void Map::handleItemChange()
{
    ListItem* item = static_cast<ListItem*>(sender());
    QModelIndex index = indexFromItem(item);
    if(index.isValid())
        emit dataChanged(index, index);
}


/*******************/

QModelIndex Map::indexFromItem(const ListItem *item) const
{
    Q_ASSERT(item);
    for(int row=0; row<m_list.size(); ++row) {
        if(m_list.at(row) == item) return index(row);
    }
    return QModelIndex();
}


QHash<int, QByteArray> Map::roleNames() const{
    return m_prototype->roleNames();
}


void Map::modifierCouleur(const int row, const QString &couleur){
    setData(indexFromRow(row), couleur, CaseMap::CouleurRole);
}

void Map::modifierPositionCase(const int row, int x, int y){
    setData(indexFromRow(row),x,CaseMap::PositionXRole);
    setData(indexFromRow(row),y,CaseMap::PositionYRole);

}

int Map::getPositionXCase(const int row) const{
    return data(indexFromRow(row),CaseMap::PositionXRole).toInt();
}

int Map::getPositionYCase(const int row) const{
    return data(indexFromRow(row),CaseMap::PositionYRole).toInt();

}



int Map::getNumeroCase(int x,int y) const{
    int pos = x + y*m_nombreCaseX;
    assert(pos>=0 && pos < m_list.size());
    return data(indexFromRow(pos),CaseMap::NumeroRole).toInt();
}


int Map::tailleCase(int width, int height){
    return qMin(width/m_nombreCaseX, height/m_nombreCaseY);
}


const QPoint Map::getDimension() const{
    return QPoint(m_nombreCaseX, m_nombreCaseY);

}

QPoint Map::numeroToPoint(int row) const{
    assert(row >=0 && row < m_nombreCaseX*m_nombreCaseY);

    int x = row%m_nombreCaseX ;
    int y = row/m_nombreCaseX;
    return QPoint(x,y);
}

Map::~Map(){
    qDeleteAll(m_list);
    m_list.clear();
    delete(m_prototype);
}
