#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSlider>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSlider *horizontalSlider_Red;
    QSlider *horizontalSlider_Green;
    QSlider *horizontalSlider_Blue;


public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
