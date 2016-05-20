#ifndef DEFAULT_H
#define DEFAULT_H

#include "strategieattaque.h"

class Default : public StrategieAttaque
{
public:
    Default(QObject *parent = 0);
    virtual QPoint cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension);
};

#endif // DEFAULT_H
