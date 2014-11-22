#include "widget.h"
#include <QPointF>
#include <QVector>
#include <QTimer>
#include <QPainter>
#include <2d_geometry.h>

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)
{

    frameNo = 0;
    points_per_frame = 100;

    geo.set_offset(600,600);
    geo.set_numpoints(10000);
    //geo.generate_circle(50);
    geo.generate_square(500);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextAnimationFrame()));
    timer->start(100);

    setBackgroundRole(QPalette::Base);
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

DisplayWidget::~DisplayWidget()
{

}

// slot to make a paintevent happen
void DisplayWidget::nextAnimationFrame()
{
    update();
}

void DisplayWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    //painter.translate(width() / 2, height() / 2);
    QPen pen = painter.pen();
    pen.setWidth(5);

    int length = points_per_frame;
    //handle the end of the point set case, where we dont want to go off the end
    if((frameNo+1)*points_per_frame > geo.points.size())
    {
        length = geo.points.size()-(frameNo*points_per_frame);
        painter.drawPolyline(geo.points.data()+(frameNo*points_per_frame), length);
        frameNo=0;
    }
    else
    //normally just use points_per_frame
    {
        painter.drawPolyline(geo.points.data()+(frameNo*points_per_frame), length);
        frameNo++;
    }

}
