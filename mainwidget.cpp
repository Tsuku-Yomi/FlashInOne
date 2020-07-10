#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    GameScene=new QGraphicsScene;
    QGraphicsScene::
}

MainWidget::~MainWidget()
{
    delete ui;
}
