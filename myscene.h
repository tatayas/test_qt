#ifndef MYSCENE_H
#define MYSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>
#include <QPointF>
#include "dialog.h"


class MyScene : public QGraphicsScene
{
    Q_OBJECT
//public:

//    Dialog *dial;

public:
    explicit MyScene(QWidget *parent = nullptr);

    // Описываем типы фигур
    enum ShapeType { Rectangle, Ellipse }; // Типы примитивов
    QColor color_ramka = Qt::lightGray;             //цвет рамки

public slots:
    void changeColor();
    void onRedSliderChanged(int value);
    void onGreenSliderChanged(int value);
    void onBlueSliderChanged(int value);


signals:
    void custom_color(int color);

    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
 //   bool m_drawingInProcess;


    // Метод для смены текущего типа фигуры
    void setShapeType(ShapeType type) { m_currentShape = type; }
private:
    ShapeType m_currentShape; // Храним текущий выбор

    QAbstractGraphicsShapeItem *m_current; // Указатель на текущий объект

   // для хранения координат левого верхнего угла прямоугольника
   //(а «тянуть» будем при нажатой правой кнопке за правый нижний угол)

    bool m_drawingInProcess;        // Флаг "Идет рисование"
    QPointF   m_startPoint;        // Точка нажатия (левый верхний угол)

    uint width_ramka = 5;               //толщина рамки
    Qt::PenStyle m_penStyle = Qt::DashDotLine;       // Стиль рамки
    QBrush color_kistochka;  //можно также задать цвет  кисти QBrush  для закрашивания

};

#endif // MYSCENE_H
