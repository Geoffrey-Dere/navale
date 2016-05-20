#ifndef ENLIGNESTRATEGIE_H
#define ENLIGNESTRATEGIE_H

#include "strategieattaque.h"

class Enligne : public StrategieAttaque
{
public:
    explicit Enligne(QObject *parent = 0);
    virtual QPoint cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension);


protected:
     QPoint m_last= QPoint( INT_MAX-2, INT_MAX-2) ;
};

#endif // ENLIGNESTRATEGIE_H
