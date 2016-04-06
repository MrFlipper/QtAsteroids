#include "station.h"
#include <QPainter>
/*************************************************************************************/
/******************* Represents a radio station in the simulation ********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

Station::Station( qreal x, qreal y ) : QGraphicsItem()
{
  // set Station pixmap and position
  setPos( x, y );
}

/************************************** paint ****************************************/

void  Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // paint station symbol, must be smaller than bounding rectangle
  painter->setRenderHint( QPainter::Antialiasing );
  painter->setPen( QPen( Qt::black, 2 ) );
  painter->drawLine( -5, -18,  0,  -6 );
  painter->drawLine( +5, -18,  0,  -6 );
  painter->drawLine( -5, -18,  +5,  -18 );
}
