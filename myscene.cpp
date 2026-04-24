#include "myscene.h"
#include <QGraphicsRectItem>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QPen>
#include "dialog.h"
#include "pattern.h"


MyScene::MyScene(QWidget *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0,0,500,500);
    m_drawingInProcess = false;
    m_current = nullptr;
}


void MyScene::changeColor()
{

    //classic Dialog

//    QString title_getColor (tr("TANYA TESTING THE COLOR"));
//    QColor color = QColorDialog::getColor(Qt::white);

//        if (color.isValid())
//        {
//           color_ramka =color;
//        }


    //my Dialog
    Dialog *dial = new Dialog();
    //Pattern *pat = new Pattern();
    //pat->show();


    int initial_red = color_ramka.red();
    int initial_green = color_ramka.green();
    int initial_blue = color_ramka.blue();

    // Проверка в консоли: что мы вообще передаем?
    qDebug() << "Sending to sliders: R=" << initial_red << "G=" << initial_green << "B=" << initial_blue;

    // 2. Инициализация СЛАЙДЕРОВ (Строгий порядок: Range -> Value)

    // КРАСНЫЙ
    dial->horizontalSlider_Red->setRange(0, 255);
    dial->horizontalSlider_Red->setValue(initial_red);

    // ЗЕЛЕНЫЙ
    dial->horizontalSlider_Green->setRange(0, 255);
    dial->horizontalSlider_Green->setValue(initial_green);

    // СИНИЙ
    dial->horizontalSlider_Blue->setRange(0, 255);
    dial->horizontalSlider_Blue->setValue(initial_blue);

    //ТОЛЩИНА
    dial->spinBox->setValue(width_ramka);

    //СТИЛЬ

    int index = dial->comboBox->findData(static_cast<int>(m_penStyle));
    if (index != -1)
    {
        dial->comboBox->setCurrentIndex(index); //установила стиль на форме, как в объявлении класса
    }



        if (dial->exec() == QDialog::Accepted)
        {
            color_ramka.setRed(dial->horizontalSlider_Red->value());
            color_ramka.setGreen(dial->horizontalSlider_Green->value());
            color_ramka.setBlue(dial->horizontalSlider_Blue->value());
            //uint width_ramka = 5;               //толщина рамки
            width_ramka = dial->spinBox->value();
            int data =dial->comboBox->currentData().toInt();
            Qt::PenStyle my_new_style = static_cast<Qt::PenStyle>(data);
            m_penStyle = my_new_style;
            QPen new_pen;
            new_pen.setColor(color_ramka);
            new_pen.setWidth(width_ramka);
            new_pen.setStyle(m_penStyle);

            update();
            qDebug() << "data struct: red = " << color_ramka.red() <<"green = " <<color_ramka.green()<< "blue = "<<color_ramka.blue();
            emit signal_change_pattern(new_pen);

        }
        else

        {
            qDebug() << "Color selection cancelled";
        }
}




void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     //qDebug() <<" first m_current = " << m_current;
     if (event->button() == Qt::RightButton)
     {
         m_startPoint = event->scenePos();

         if (m_currentShape==Rectangle)
         {
            m_current=new QGraphicsRectItem(m_startPoint.x(),m_startPoint.y(),0.,0.);
            qDebug() <<"m_current = " << typeid(*m_current).name();

         }

         if (m_currentShape==Ellipse)
         {
             m_current=new QGraphicsEllipseItem(m_startPoint.x(),m_startPoint.y(),0.,0.);
             qDebug() <<"m_current = " << typeid(*m_current).name();

         }

         if (m_currentShape==Marker)
         {
             m_startPoint = event->scenePos();

             QPainterPath path;
             path.moveTo(m_startPoint); // Начальная точка

             auto *pathItem = new QGraphicsPathItem();
             pathItem->setPath(path);

             // Настройка "маркера"
//             QPen pen(Qt::yellow, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
//             pathItem->setPen(pen);
//             pathItem->setOpacity(0.5); // Полупрозрачность для эффекта маркера

             m_current = pathItem;

         }



         // Создаем перо с текущими атрибутами (пункт 6)
         QPen pen;
         //color_ramka.yellow();

         qDebug() <<"color_ramka_begin = " << color_ramka;
         //color_ramka = QColor(Qt::blue);


         //width_ramka = 20;
         pen.setColor(color_ramka); // Цвет из поля класса
         pen.setWidth(width_ramka);    // Толщина из поля класса
         pen.setStyle(m_penStyle);     // Стиль (например, Qt::SolidLine)

         qDebug() <<"color_ramka_end = " << color_ramka;

         // Ассоциируем перо и кисть с примитивом
         m_current->setPen(pen);         // Устанавливаем рамку
         m_current->setBrush(color_kistochka);   // Устанавливаем заливку (пункт 6)
         m_current->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
         m_current->setBrush(color_kistochka);
         // 4. Устанавливаем начальную позицию объекта на сцене
         m_current->setPos(m_startPoint);

         // 5. ДОБАВЛЯЕМ ОБЪЕКТ НА СЦЕНУ
         addItem(m_current);

         m_drawingInProcess =true;
         update();

     }

     if (event->button()==Qt::LeftButton)
     {
         m_drawingInProcess =false;
     }

     // Не забываем вызвать базовый обработчик, чтобы работали стандартные функции (например, выбор)
     QGraphicsScene::mousePressEvent(event);


}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() <<"color_ramka_end = " << color_ramka;
    if (m_drawingInProcess && m_current)
    {
           // Вычисляем размеры относительно стартовой точки
           qreal width =   event->scenePos().x() - m_startPoint.x() ;
           //qDebug() <<"width = " << width;
           qreal height =  event->scenePos().y() - m_startPoint.y() ;
           //qDebug() <<"height = " << height;

           if (m_currentShape==Rectangle)
           {
                QGraphicsRectItem*  new_cur = qgraphicsitem_cast<QGraphicsRectItem*>(m_current);
                if (new_cur)
                {
                    new_cur->setRect(0,0,width,height);
                }
           }

           if (m_currentShape==Ellipse)
           {
                QGraphicsEllipseItem*  new_cur = qgraphicsitem_cast<QGraphicsEllipseItem*>(m_current);
                if (new_cur)
                {
                    new_cur->setRect(0,0,width,height);
                }
           }

           if (m_currentShape==Marker)
           {
               QGraphicsPathItem * new_cur = nullptr;
               new_cur = qgraphicsitem_cast<QGraphicsPathItem*>(m_current);
               if (new_cur)
               {
                   QPainterPath path = new_cur->path();
                   path.lineTo(event->scenePos());
                   new_cur->setPath(path);

               }
           }



          // new_cur->normalized();
          // rect_obj->normalized();
           //if (rect_obj) rect_obj->setRect(rect_real);
       }
       QGraphicsScene::mouseMoveEvent(event);


}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    //m_drawingInProcess =false;
    if (m_drawingInProcess)
    {
        m_current = nullptr;
        m_drawingInProcess =false;
    }

    QGraphicsScene::mouseReleaseEvent (event);
}
