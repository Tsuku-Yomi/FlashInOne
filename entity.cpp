#include "entity.h"

Entity::Entity(
                   QGraphicsItem *parent=NULL,
                   int SpawnHP=-1,
                   Speed SpawnSpd=Speed())
    :QGraphicsItem(
         parent
        )
{
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}
