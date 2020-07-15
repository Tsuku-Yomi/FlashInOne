#ifndef BASESTAND_H
#define BASESTAND_H

//基本物理结构

struct Speed
{
    int dx,dy;
    Speed(int _dx=0,int _dy=0):dx(_dx),dy(_dy)
    {

    }
    inline void SpeedMove(int &x,int &y)
    {
        x+=dx;
        y+=dy;
    }
    inline void AddSpeed(int _dx,int _dy)
    {
        dx+=_dx;
        dy+=_dy;
    }
};

struct BasicAttribute
{
    bool UnBreakable;
    double CollisionSizeRadius;



    BasicAttribute(bool _UnBreakable=false,
                   double _CollisionSizeRadius=1
                  ):
    UnBreakable(_UnBreakable),
    CollisionSizeRadius(_CollisionSizeRadius)
    {

    }
};


#endif // BASESTAND_H
