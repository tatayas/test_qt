#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myscene.h"
#include <QColor>
#include <QColorDialog>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyScene *scene=new MyScene();//создаем НАШУ сцену
    //Например,
    ui->graphicsView->setScene(scene); //и ассоциируем ее с QGraphicsView
    QObject::connect(ui->actionChange_Color,SIGNAL(triggered()), scene, SLOT(changeColor()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::changeColor()
//{

//}
