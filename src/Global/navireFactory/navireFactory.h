#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include "QList"
#include "../Navire/navire.h"
#include <QMetaEnum>
#include <QDebug>

class NavireFactory : public QObject
{
    Q_OBJECT
public:
    enum Type{
        SIMPLE = 0,
        MOSAIQUE
    };
    Q_ENUMS(Type)

    enum Epoque{
        XVI=0,
        XX
    };
    Q_ENUMS(Epoque)


    explicit NavireFactory(QObject *parent = 0);

    // retourne la liste de toutes les époques possibles
    static const QStringList getListType() ;
    static const QStringList getListEpoque();

    //créer les navires
    virtual QList<Navire*> creerNavire(int nombre, int resistanceNavire) = 0;

    static Type StringtoType(QString type); // retourne Type en fonction du string
    static Epoque EpoqueStringtoType(QString  type);

private :
    static QHash<Type,QString> creerDico();
    static QHash<Type,QString> m_dictionnaire ; // correspondance entre le type (enum) et description QString

    static QHash<Epoque,QString> creerDicoEpoque();
    static QHash<Epoque,QString> m_dictionnaireEpoque ;

};

#endif // FACTORY_H
