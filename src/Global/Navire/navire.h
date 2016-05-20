#ifndef NAVIRE_H
#define NAVIRE_H

#include <QObject>
#include <QDebug>
#include <QImage>
#include <QVector>
#include <assert.h>

class Navire : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int taille READ getTaille CONSTANT)
    Q_PROPERTY(bool horizontale READ estHorizontale CONSTANT)
    Q_PROPERTY(QString imageNavire READ image CONSTANT)


public:
    explicit Navire(int resistanceNavire, int taille, QString image , QObject *parent = 0);
    virtual QString getFond() const = 0;
    virtual QString getNom() const = 0;

    int getTaille();
    bool estHorizontale();
    void setHorizontale(bool e);
    int getDurabiliteAt(int i);
    bool setDurabiliteAt(int i);
    int getMaxDurabilite();
    bool estDetruit();

signals:
    void durabiliteChanged();

public slots:

    inline QString image(){
        return m_image;
    }

protected:
    int m_taille;
    bool m_horizontale;
    QString m_image;
    QVector<int> m_durabilite ;

};

#endif // NAVIRE_H
