#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
    , ui(new Ui::MainWindow)
{
    scence = new QGraphicsScene(this);
    work =  new Work(this);
    Work *x = new Work(this);
    setScene(scence);
    scence->addItem(work);
    scence->addItem(work);
    connect(work, SIGNAL(reDraw()),this,SLOT(reDraw()));
    connect(work, SIGNAL(dblClick()),this,SLOT(randomColor()));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reDraw()
{
scence->update();
update();
}

void MainWindow::randomColor()
{
    work->setBrush(QBrush(QColor(rand() % 256, rand() % 256, rand()% 256)));
}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        delete work;

        //scence->addItem(x);
    }
}

