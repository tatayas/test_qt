#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // Проверка существования groupBox_3
//    if (ui->groupBox_3) {
//        qCritical() << "GroupBox_3 not found in UI!";
//        return;
//    }
    //horizontalSlider_Red = new QSlider(Qt::Horizontal);
    //horizontalSlider_Green = new QSlider(Qt::Horizontal);
    //horizontalSlider_Blue = new QSlider(Qt::Horizontal);
    qDebug() << "Available widgets:";
    qDebug() << "groupBox_3:" << ui->groupBox_3;
    qDebug() << "horizontalSlider_Red:" << ui->horizontalSlider_Red;
    qDebug() << "horizontalSlider_Green:" << ui->horizontalSlider_Green;
    qDebug() << "horizontalSlider_Blue:" << ui->horizontalSlider_Blue;

    horizontalSlider_Red = ui->horizontalSlider_Red;
    horizontalSlider_Green = ui->horizontalSlider_Green;
    horizontalSlider_Blue = ui->horizontalSlider_Blue;

    qDebug() << "Slider linked to UI:" << horizontalSlider_Red;


}


void Dialog::updateColor(int value)
{



    ui->horizontalSlider_Blue->setValue(value);

    // Обновляем текущий цвет
    //currentColor.setBlue(blue);

    // Здесь вы можете использовать эти значения:
        // — сохранить в переменные,
        // — передать в другой модуль,
        // — вывести в консоль или на экран.
        //qDebug() << "RGB: " <<red << ", " << green << ", " << blue;

        update();



}


//void Dialog::changeSliders(in)
//{

//}

Dialog::~Dialog()
{
    delete ui;
}
