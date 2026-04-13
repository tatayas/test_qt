#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    horizontalSlider_Red = new QSlider;
    horizontalSlider_Green = new QSlider;
    horizontalSlider_Blue = new QSlider;
    qDebug() << "horizontalSlider_Blue = " << horizontalSlider_Blue->sliderPosition();



}

Dialog::~Dialog()
{
    delete ui;
}
