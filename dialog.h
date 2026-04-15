#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>

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



private slots:
    //void updateColor(int color_blue);

    //void on_comboBox_currentIndexChanged(int index);

signals:
    void changeSliders(int);

public slots:
    //void ChangeLine(int);



private:
    QColor currentColor;


public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};



#endif // DIALOG_H
