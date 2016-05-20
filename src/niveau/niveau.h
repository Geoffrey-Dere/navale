#ifndef NIVEAU_H
#define NIVEAU_H

#include <QObject>


class Niveau : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nom READ getNom CONSTANT)
    Q_PROPERTY(QString description READ getDescription  CONSTANT)

public:
    explicit Niveau(QString nom, QObject *parent = 0);
    QString afficher();

    inline QString getDescription() {return afficher();}

    virtual int resistanceNavireOrdi() = 0;
    virtual int resistanceNavireJoueur() = 0;


signals:

public slots :
    QString getNom();

protected :
    QString m_nom;

};

#endif // NIVEAU_H
