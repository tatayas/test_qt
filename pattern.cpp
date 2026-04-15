#include "pattern.h"
#include <QPainter>
#include <QLine>

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{

}


void Pattern::paintEvent(QPaintEvent *event)
{
    QPainter paint_up(this);
    paint_up.drawLine(0, 0, this->width(), this->height());

QWidget::paintEvent(event);
}
