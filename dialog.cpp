#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QStringList>



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

//    QStringList list;
//    list << "Solid line" << "Dashing line";
//    ui->comboBox->addItems(list);

    ui->comboBox->addItem("Сплошная линия",  static_cast<int>(Qt::SolidLine));
    ui->comboBox->addItem("Пунктир",         static_cast<int>(Qt::DashLine));
    ui->comboBox->addItem("Точки",           static_cast<int>(Qt::DotLine));
    ui->comboBox->addItem("Штрих-пунктир",    static_cast<int>(Qt::DashDotLine));



    spinBox = ui->spinBox;
    comboBox=ui->comboBox;
    pattern  =ui->widget;

    //connect(comboBox, SIGNAL(activated(int)),this,SLOT(ChangeLine(int)));
    //ui->comboBox->installEventFilter(this);
   // qDebug() << "Slider linked to UI:" << horizontalSlider_Red;

    connect(horizontalSlider_Red, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    connect(horizontalSlider_Green, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    connect(horizontalSlider_Blue,SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    connect(spinBox,SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    connect(comboBox,SIGNAL(activated(int)), this, SLOT(slotSomebodyChanged()));
    connect(this, SIGNAL(signalChangePattern(QPen)), pattern, SLOT(slotChangePen(QPen)));

}

void Dialog::slotSomebodyChanged()
{
    QPen from_new_settings_pen;
    QColor new_color;
    new_color.setRed(horizontalSlider_Red->value());
    new_color.setGreen(horizontalSlider_Red->value());
    new_color.setBlue(horizontalSlider_Blue->value());
    from_new_settings_pen.setColor(new_color);
    //from_new_settings_pen.setStyle(comboBox->get);
    int data =comboBox->currentData().toInt();
    //Qt::PenStyle my_new_style = static_cast<Qt::PenStyle>(data);
    //m_penStyle = my_new_style;

    from_new_settings_pen.setStyle(static_cast<Qt::PenStyle>(data));
    //int width = spinBox->value();
    from_new_settings_pen.setWidth(spinBox->value());
    emit signalChangePattern(from_new_settings_pen);


}


Dialog::~Dialog()
{
    delete ui;
}


