#include "caseMap.h"

CaseMap::CaseMap(int numero, const QString &couleur, QObject *parent) :
  ListItem(parent), m_numero(numero), m_couleur(couleur)
{
}


QHash<int, QByteArray> CaseMap::roleNames() const
{
  QHash<int, QByteArray> names;
  names[NumeroRole] = "numeroCase";
  names[CouleurRole] = "couleurCase";
  names[PositionXRole] = "positionX";
          names[PositionYRole] = "positionY";
  return names;
}

QVariant CaseMap::data(int role) const
{
  switch(role) {
  case NumeroRole:
    return numero();
  case CouleurRole:
    return couleur();
  case PositionXRole:
      return getX();
  case PositionYRole:
      return getY();
  default:
    return QVariant();
  }
}


bool CaseMap::setCouleur(QString couleur) {
    m_couleur = couleur;
    emit dataChanged();
    return true;
}

bool CaseMap::setData(const QVariant & value, int role){

    switch(role){
    case CouleurRole:
        return setCouleur(value.toString());
      case PositionXRole:
        return setX(value.toInt());
    case PositionYRole:
        return setY(value.toInt());
    }
    return false;
}


 bool CaseMap::setX(int x){
  m_x = x;
  return true;
 }

 bool CaseMap::setY(int y){
     m_y = y;
     return true;
 }

