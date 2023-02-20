#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QBrush>


class Work: public QObject, public QGraphicsItem
{
Q_OBJECT
Q_PROPERTY(QBrush brush)
public:
explicit Work(QObject *parent = nullptr);
void setBrush(QBrush brush) {this->brush = brush; emit reDraw();}
signals:
void reDraw();
void dblClick();
public slots:
private:
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget
*widget);
QRectF boundingRect() const;
private:
enum Geometry {RECTANGLE, ELLIPS};
int x, y;
Geometry geometry;
QPoint bpoint;
bool moving;
QBrush brush;
QPainter *painter2;
protected:
void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // WORK_H
