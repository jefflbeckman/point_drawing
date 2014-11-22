#ifndef geo_H
#define geo_H

#include <QPointF>
#include <QVector>

//singleton containing methods to generate a variety of shapes
//output as a vector<QPointF> for use by the QT library drawPolyline function
class geo_generator
{
public:

    geo_generator();
    std::vector<QPointF> generate_ellipse(int x_ratio, int y_ratio);
    std::vector<QPointF> generate_circle(int radius);
    std::vector<QPointF> generate_rectangle(int width, int height);
    std::vector<QPointF> generate_square(int side);

    void set_numpoints(int num_points);
    int get_numpoints();
    void set_offset(int x, int y);
    void get_offset(int* x, int* y);
    std::vector<QPointF> points;

private:
    int num_points;
    int x_offset, y_offset;

};

#endif // geo_H
