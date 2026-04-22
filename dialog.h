#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include "pattern.h"

namespace Ui {
class Dialog;
}

struct Data_data
{
    int red_color;
    int green_color;
    int blue_color;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSlider *horizontalSlider_Red;
    QSlider *horizontalSlider_Green;
    QSlider *horizontalSlider_Blue;
    QSpinBox *spinBox;
    QComboBox *comboBox;
    Pattern *pattern;



private slots:
    //void updateColor(int color_blue);

    //void on_comboBox_currentIndexChanged(int index);

signals:
    void changeSliders(int);
    void signalChangePattern(QPen pen);

public slots:
    //void ChangeLine(int);
    void slotSomebodyChanged();



private:
    QColor currentColor;


public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};



#endif // DIALOG_H
