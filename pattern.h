#ifndef PATTERN_H
#define PATTERN_H

#include <QObject>
#include <QWidget>
#include <QPen>

class Pattern : public QWidget
{
    Q_OBJECT
    QPen *pen_pattern;

public:
    explicit Pattern(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // PATTERN_H
