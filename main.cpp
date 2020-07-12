#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene* GameScene=new QGraphicsScene(-200,-200,400,400);
    MainView w(GameScene);
    w.show();
    return a.exec();
}
