#ifndef STRATEGIEATTAQUE_H
#define STRATEGIEATTAQUE_H

#include <QObject>
#include <QPoint>
#include <QVector>
#include <QDateTime>
#include <QDebug>
/**
 * @brief The StrategieAttaque class
 * classe abstraite
 */
class StrategieAttaque : public QObject
{
    Q_OBJECT
public:
    explicit StrategieAttaque(QObject *parent = 0);
    virtual QPoint cibler( const QVector<QPoint>* coup_dispo, const QPoint& map_dimension) = 0;

signals:

public slots:
};

#endif // STRATEGIEATTAQUE_H
