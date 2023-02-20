#include "work.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

Work::Work(QObject *parent) : QObject(parent), QGraphicsItem()
{
    x = 0;
    y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
    geometry = Geometry::ELLIPS; // По умолчанию - эллипс
    setPos(0,0);
    moving = false;
}

void Work::paint(QPainter *painter, const QStyleOptionGraphicsItem
*option, QWidget *widget)
{
painter->setBrush(brush);
if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
Q_UNUSED(option)
Q_UNUSED(widget)
}

QRectF Work::boundingRect() const // Обязателен для
// переопределения
{
return QRectF(x, y, 200, 100); // Текущие координаты
}

void Work::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
if (event->button() == Qt::LeftButton) // Левая кнопка, режим
// перемещения
{
moving = true; // Флаг активности
// перемещения
bpoint = event->pos().toPoint(); // Запоминаем начальные
// координаты мыши
}
if (event->button() == Qt::RightButton) // Правая кнопка - меняем вид
// фигуры
{
if (geometry == Geometry::ELLIPS)
{
geometry = Geometry::RECTANGLE;
} else geometry = Geometry::ELLIPS;
emit reDraw();
}
}
void Work::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
if (event->button() == Qt::LeftButton)
{
moving = false; // Снимаем флаг на
// перемещение
emit reDraw();
}
}

void Work::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
if (moving) // Если активен флаг
// перемещения
{
// Вычисляем вектор смещения
QPoint p = event->pos().toPoint() - bpoint;
x += p.x();
y += p.y();
bpoint = event->pos().toPoint(); // Запоминаем новую позицию
// курсора
emit reDraw(); // Переотрисовываем
}
}
void Work::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
if (event->button() == Qt::RightButton)
{
emit dblClick(); // Отправляем сигнал
// о двойном клике
}
if(event->button() == Qt::LeftButton)
{
}
}



