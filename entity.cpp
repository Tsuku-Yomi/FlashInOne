#include "entity.h"

const int PicSize=72/*or 144*/;

Entity::Entity(
                   QGraphicsItem *parent,
                   int SpawnHP,
                   Speed SpawnSpd,
                   BasicAttribute _EntityAtt)//这个缩进不会看不懂吧
    :QGraphicsItem(
         parent
        )
{
    E_att=new BasicAttribute(_EntityAtt);
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

int Entity::Be_Hit(int Damage)//返回1，代表不销毁，返回0，代表销毁，返回-1，代表不调用摧毁函数直接销毁，其他返回值留给子类重载时使用
{
     if(!E_att->UnBreakable)
     {
         HealthPoint-=Damage;
         if(HealthPoint<=0)
         {
             return 0;
         }
     }
     return 1;
}

QRectF Entity::boundingRect()
{
    return QRectF(-PicSize/2,-PicSize/2,PicSize,PicSize);
}

bool Entity::collidesWithItem(
        const QGraphicsItem *other,
        Qt::ItemSelectionMode mode
                              )
{
    //这里留着写碰撞
}
