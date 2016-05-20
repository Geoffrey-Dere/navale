#include "enligne.h"

Enligne::Enligne(QObject *parent)
    : StrategieAttaque(parent)
{

}

QPoint Enligne::cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension){

    while(coup_dispo->size() == 0 || !coup_dispo->contains(m_last)){

        m_last.setX(m_last.x() +1 );

        if(m_last.x() >= map_dimension.x() || m_last.y() >= map_dimension.y())
            m_last = coup_dispo->value(qrand()%coup_dispo->size());
    }

    return QPoint(m_last.x(), m_last.y());
}


