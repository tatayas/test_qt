#include "pattern.h"
#include <QPainter>
#include <QLine>

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{

}


void Pattern::paintEvent(QPaintEvent *event)
{
//    pen_pattern = new QPen();
//    QPoint tochka_verh = even
//    QLine *line =new QLine()


    QPainter paint_up(this);

    paint_up.drawLine(0, 0, this->width(), this->height());
//    paint_up.translate(0,0);
//    QPainter paint_dawn(this);
//    paint_dawn.translate(this->width(), this->height());
//    QLine *line_pattern;
//    line_pattern.

    //paint.translate(this->width()/2, this->height()/2);
//    if (m_nextFigure)
//    {
//        m_nextFigure->drawFig(paint);
//        //update();
//    }

QWidget::paintEvent(event);
}
