#include "navire.h"

Navire::Navire(int resistanceNavire, int taille, QString image, QObject *parent)
    : m_image(image), QObject(parent)
{
   m_taille = taille;
   m_durabilite =  QVector<int>(m_taille,resistanceNavire);
   m_durabilite.append(resistanceNavire); // max durabilite
}

int Navire::getTaille(){
    return m_taille;
}

bool  Navire::estHorizontale(){
    return m_horizontale;
}

void  Navire::setHorizontale(bool e){
    m_horizontale = e;
}


int  Navire::getDurabiliteAt(int i){
     assert(i < m_taille && i >=0);
     return  m_durabilite.at(i);

}

bool  Navire::setDurabiliteAt(int i){
    assert(i < m_taille && i >=0);

    if(m_durabilite.at(i) > 0)
        m_durabilite[i] = m_durabilite[i]-1;

    emit durabiliteChanged();
    return m_durabilite.at(i)!=0;

}

 bool Navire::estDetruit(){

     for(int i = 0; i < m_taille ; i++)
         if(m_durabilite.at(i) != 0)
             return false;
     return true;

 }

 int Navire::getMaxDurabilite(){
     return m_durabilite[m_taille];
 }
