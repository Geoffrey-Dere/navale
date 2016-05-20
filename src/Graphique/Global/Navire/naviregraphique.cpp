#include "naviregraphique.h"


NavireGraphique::NavireGraphique( QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

Navire* NavireGraphique::modele(){
    return m_navire;
}
void NavireGraphique::setModele(Navire* navire){

    assert(navire!=nullptr);

    m_navire = navire;
    connect(m_navire, SIGNAL(durabiliteChanged()), this, SLOT(update()));
    emit modeleChanged();
}


void NavireGraphique::paint(QPainter *painter){


    int largeur_carre = boundingRect().width();
    int hauteur_carre = boundingRect().height();

    if(m_navire->estHorizontale())
        largeur_carre/= m_navire->getTaille();
    else
        hauteur_carre/= m_navire->getTaille();

    int x = 0, y = 0;
    int tmp = hauteur_carre;


    if (QFileInfo(m_navire->getFond() ).exists()){ // si image

        QImage image(m_navire->getFond());
        int taille =  m_navire->getTaille();

        int posXI = 0, posYI = 0; // position image
        int divX = m_navire->estHorizontale() == true ? taille : 1;
        int divY = m_navire->estHorizontale() == true ? 1 : taille;


        for(int i = 1; i <= taille ; i++){
            double opacite = (double) m_navire->getDurabiliteAt(i-1) / (double ) m_navire->getMaxDurabilite();
            painter->setOpacity(opacite);

            if(opacite==0)
                dessinerCroix(painter, x,y, largeur_carre, hauteur_carre);

            else{
                QRectF source(posXI*image.width()/divX , posYI*image.height()/divY, image.width()/divX, image.height()/divY);
                QRectF target(x,y, largeur_carre, hauteur_carre);
                painter->drawImage(target,image, source);
            }

            if(m_navire->estHorizontale()){
                x+= tmp; posXI++;
            }
            else{
                y+=tmp; posYI++;
            }
        }


    } else { // aucune image pour le navire, on affiche un fond

        QColor couleur(m_navire->getFond());
        QBrush fond(couleur);
        painter->setBrush(fond);
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing);

        for(int i = 0; i < m_navire->getTaille() ; i++){
            double opacite = (double) m_navire->getDurabiliteAt(i) / (double ) m_navire->getMaxDurabilite();

            if(opacite==0)
                dessinerCroix(painter, x,y, largeur_carre, hauteur_carre);
            else
                painter->drawRoundedRect(x,y, largeur_carre, hauteur_carre , 0, 0);

            if(m_navire->estHorizontale())
                x+= tmp;
            else
                y+=tmp;
        }
    }
}


void NavireGraphique::dessinerCroix(QPainter * painter, int x, int y, int w, int h){
    QImage croix (":/image/../image/croix.png");
    QRectF source(0, 0 , croix.width(), croix.height());
    QRectF target(x, y, w, h);
    painter->setOpacity(1);
    painter->drawImage(target,croix, source);
}
