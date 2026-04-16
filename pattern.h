#ifndef PATTERN_H
#define PATTERN_H

#include <QObject>
#include <QWidget>
#include <QPen>
#include <QPainter>

class Pattern : public QWidget
{
    Q_OBJECT


public:
    //QPen *m_pattern_pen;

    QColor m_color = Qt::black;
    int m_width = 1;
    Qt::PenStyle m_style = Qt::SolidLine;
    QPen m_pen;

public:
    explicit Pattern(QWidget *parent = nullptr);

public slots:
    void slotChangePen(QPen newPen);


signals:


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // PATTERN_H
