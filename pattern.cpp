#include "pattern.h"
#include <QDebug>

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{
    //resize(400, 400);
    setStyleSheet("background-color: red;");
}

void Pattern::slotChangePen(QPen newPen)
{
//    m_color = newPen->color();
//    m_width =newPen->width();
//    m_style = newPen->style();

    m_pen = newPen;
    update();
}


void Pattern::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event); // Вызов базы
    QPainter painter(this);
   // Рисуем линию: от (0,0) до (ширина, высота)


    QPen penn(m_color, m_width, m_style);

   painter.setPen(penn); // Цвет линии
   painter.drawLine(0, 0, this->width(), this->height());
   qDebug() << "Рисую!";
   update();

}
