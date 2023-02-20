#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "work.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QGraphicsView
{
    Q_OBJECT
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void reDraw();

    void randomColor();

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *scence;
    Work *work;
};
#endif // MAINWINDOW_H
