#include "factorymosaique.h"


FactoryMosaique::FactoryMosaique(QObject *parent) : NavireFactory(parent)
{

}

//FactoryMosaique* FactoryMosaique::getFactory(int periode){
//    return nullptr;
//}


QList<Navire *> FactoryMosaique::creerNavire(int nombre, int resistanceNavire){
    QList<Navire*> list;

    while (nombre>0){
        list.append(nouveauNavire2D(resistanceNavire));
        nombre--;

        if(nombre>0){
            list.append(nouveauNavire3D(resistanceNavire));
            nombre--;
        }

        if(nombre>0){
            list.append(nouveauNavire4D(resistanceNavire));
            nombre--;
        }
    }
    return list;
}
