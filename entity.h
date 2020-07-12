#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
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
            Speed SpawnSpd=Speed()
          );
    virtual ~Entity();
    virtual int Tick_Work()=0;
    virtual void Destroy();

private:
    int HealthPoint;
    Speed Spd;
};

#endif // ENTITY_H
