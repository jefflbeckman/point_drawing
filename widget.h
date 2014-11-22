#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "2d_geometry.h"



class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    DisplayWidget(QWidget *parent = 0);

    ~DisplayWidget();


    unsigned int frameNo;
    unsigned int points_per_frame;

    QTimer* timer;

public slots:
    void nextAnimationFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    geo_generator geo;
};

#endif // WIDGET_H
