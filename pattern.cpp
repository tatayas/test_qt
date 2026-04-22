#include "pattern.h"
#include <QDebug>

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{
    //resize(400, 400);
    setStyleSheet("background-color: red;");
}

void Pattern::slotChangePen(QPen newPen)
{
    m_color = newPen.color();
    m_width =newPen.width();
    m_style = newPen.style();

    m_pen = newPen;
    update();
}


void Pattern::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
   // Рисуем линию: от (0,0) до (ширина, высота)
    m_pen.setColor(m_color);
    m_pen.setWidth(m_width);
    m_pen.setStyle(m_style);

    //QPen penn(m_color, m_width, m_style);

   painter.setPen(m_pen); // Цвет линии
   painter.drawLine(0, 0, this->width(), this->height());
   qDebug() << "Рисую!";
   //update();

       QWidget::paintEvent(event); // Вызов базы

}
