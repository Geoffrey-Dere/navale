#include "default.h"

Default::Default(QObject* parent) : StrategieAttaque(parent)
{

}

QPoint Default::cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension){

    int rand = qrand() % coup_dispo->size();
    return coup_dispo->at(rand);
}
