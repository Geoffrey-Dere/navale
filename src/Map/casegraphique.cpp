#include "casegraphique.h"

CaseGraphique::CaseGraphique( QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}


void CaseGraphique::setCouleur(const QString& c){

    m_couleur = QColor(c);
    update();
    emit couleurChanged();
}

void CaseGraphique::paint(QPainter *painter){

    QBrush fond(m_couleur);

    painter->setBrush(fond);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::Antialiasing);

    painter->drawRoundedRect(0,0, boundingRect().width(), boundingRect().height(), 0, 0);
}

