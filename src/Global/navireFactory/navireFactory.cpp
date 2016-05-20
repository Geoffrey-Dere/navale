#include "navireFactory.h"

QHash<NavireFactory::Type,QString> NavireFactory::m_dictionnaire = NavireFactory::creerDico();
QHash<NavireFactory::Epoque,QString> NavireFactory::m_dictionnaireEpoque = NavireFactory::creerDicoEpoque();

NavireFactory::NavireFactory(QObject *parent) : QObject(parent)
{

}


const QStringList NavireFactory::getListType() {

    QStringList list = QStringList();
    const QMetaObject & mo = NavireFactory::staticMetaObject;
    QMetaEnum stateEnum = mo.enumerator(mo.indexOfEnumerator("Type"));

    for(int i = 0; i < stateEnum.keyCount(); ++i) {
        list.append(m_dictionnaire[(Type)i]) ;
    }
    return list;

}

const QStringList NavireFactory::getListEpoque() {

    QStringList list = QStringList();
    const QMetaObject & mo = NavireFactory::staticMetaObject;
    QMetaEnum stateEnum = mo.enumerator(mo.indexOfEnumerator("Epoque"));

    for(int i = 0; i < stateEnum.keyCount(); ++i) {
        list.append(m_dictionnaireEpoque[(Epoque)i]) ;
    }
    return list;

}


QHash<NavireFactory::Type,QString> NavireFactory::creerDico(){
    QHash<Type,QString> dico;
    dico.insert(Type::SIMPLE, "simple");
    dico.insert(Type::MOSAIQUE, "mosaique");
    return dico ;
}

QHash<NavireFactory::Epoque,QString> NavireFactory::creerDicoEpoque(){
    QHash<Epoque,QString> dico;
    dico.insert(Epoque::XX, "20ième siècle");
    dico.insert(Epoque::XVI, "16ième siècle");
    return dico ;
}


NavireFactory::Type NavireFactory::StringtoType(QString  type){
    return m_dictionnaire.key(type);

}

NavireFactory::Epoque NavireFactory::EpoqueStringtoType(QString  type){
    return m_dictionnaireEpoque.key(type);

}
