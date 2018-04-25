#include "point.h"

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) : Point()
{
    (*this).x = x;
    (*this).y = y;

    //this->x = x;
    //this->y = y;
}
