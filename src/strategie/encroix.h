#ifndef ENCROIXSTRATEGIE_H
#define ENCROIXSTRATEGIE_H

#include "strategieattaque.h"

class EnCroix :  public StrategieAttaque
{
public:
    EnCroix(QObject *parent = 0);
    ~EnCroix();
    virtual QPoint cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension);

protected:
    QPoint m_last= QPoint( INT_MAX-2, INT_MAX-2) ;
};

#endif // ENCROIXSTRATEGIE_H
