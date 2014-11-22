#include "2d_geometry.h"
#include <QPointF>
#include <QVector>
#include <math.h>

geo_generator::geo_generator() : num_points(100), x_offset(0), y_offset(0)
{
    points.reserve(num_points);
}

std::vector<QPointF> geo_generator::generate_ellipse(int x_ratio, int y_ratio)
{
  float theta = 0.0;

  points.clear();
  points.reserve(num_points);

  for(int i = 0; i < num_points; ++i)
  {
      points.push_back(QPointF(x_offset + x_ratio*cos(theta),y_offset + y_ratio*sin(theta)));
      theta = theta+2*M_PI/num_points;
  }
  return points;
}

std::vector<QPointF> geo_generator::generate_circle(int radius)
{
    return this->generate_ellipse(radius,radius);
}

//x_offset, y_offset is center of rectangle
std::vector<QPointF> geo_generator::generate_rectangle(int width, int height)
{
    points.clear();

    //round the size of the points down to a multiple of 4
    num_points = num_points - (num_points % 4);
    points.reserve(num_points);
    //ratios of points
    int num_points_width = (num_points*width)/((width+height)*4);
    int num_points_height = (num_points*height)/((width+height)*4);
    //top (varying -x)
    for(int i = 0; i < num_points_width; ++i)
    {
        points.push_back(QPointF(x_offset+(width/2.0) - (i/((qreal)num_points_width)*(width)),
                                 y_offset+height/2));
    }

    //left (varying -y)
    for(int i = 0; i < num_points_height; ++i)
    {
        points.push_back(QPointF(x_offset-(width/2.0),
                                 y_offset+height/2.0 - (i/((qreal)num_points_height)*(height))));
    }

    //bottom (varying +x)
    for(int i = 0; i < num_points_width; ++i)
    {
        points.push_back(QPointF(x_offset-(width/2.0) + (i/((qreal)num_points_width)*(width)),
                                 y_offset-height/2));
    }

    //right (varying +y)
    for(int i = 0; i < num_points_height; ++i)
    {
        points.push_back(QPointF(x_offset+(width/2.0),
                                 y_offset-height/2.0 + (i/((qreal)num_points_height)*(height))));
    }

    return points;
}

std::vector<QPointF> geo_generator::generate_square(int side)
{
    return generate_rectangle(side,side);
}

void geo_generator::set_numpoints(int num_points)
{
    this->num_points=num_points;
}

int geo_generator::get_numpoints()
{
    return this->num_points;
}

void geo_generator::set_offset(int x, int y)
{
    this->x_offset=x;
    this->y_offset=y;
}

void geo_generator::get_offset(int* x, int* y)
{
    *x = this->x_offset;
    *y = this->y_offset;
}
