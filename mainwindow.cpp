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
    scene=new MyScene();//создаем НАШУ сцену
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

void MainWindow::on_action_Rect_triggered()
{
    scene->setShapeType(MyScene::Rectangle);
}

void MainWindow::on_Action_Ellipse_triggered()
{
    scene->setShapeType(MyScene::Ellipse);
}

void MainWindow::on_action_marker_triggered()
{
    scene->setShapeType(MyScene::Marker);
}
