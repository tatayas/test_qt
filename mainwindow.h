#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MyScene *scene;

//public slots:
    //void changeColor();


signals:
    void sigColor_blue(int color_blue);

private slots:
    void on_action_Rect_triggered();

    void on_Action_Ellipse_triggered();

    void on_action_marker_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
