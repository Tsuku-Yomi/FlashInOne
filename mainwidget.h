#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QTime>
#include "entity.h"

//运行界面

class MainView:public QGraphicsView
{
public:
    MainView(QGraphicsScene*);
protected:
    void resizeEvent(QResizeEvent *) override;
};

#endif // MAINWIDGET_H
