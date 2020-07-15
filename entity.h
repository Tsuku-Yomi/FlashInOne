#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QRect>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include "basestand.h"

//实体基类

class Entity:public QGraphicsItem
{
public:
    Entity(
            QGraphicsItem *parent=NULL,
            int SpawnHP=-1,
            Speed SpawnSpd=Speed(),
            BasicAttribute _EntityAtt=BasicAttribute()
          );
    virtual ~Entity();
    virtual int Tick_Body_Work()=0;
	virtual int Tick_AI_Work()=0;
    virtual void Destroy();
	virtual int Be_Hit(int Damage);
	virtual bool Tick_Run_Fun();//帧运行函数
private:
    //实现QGraphicsItem类的纯虚函数
    virtual QRectF boundingRect()override;
    virtual bool collidesWithItem(
            const QGraphicsItem *other,
            Qt::ItemSelectionMode mode = Qt::IntersectsItemShape
          );
    virtual paint();

    //
    BasicAttribute* E_att;//实体基本属性
    int HealthPoint;
    Speed Spd;
};

#endif // ENTITY_H
