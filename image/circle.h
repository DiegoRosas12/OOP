#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "point.h"
#include "color.h"

class Circle {
    public:

    Circle();
    Circle(Point center, double radius, Color fill=Color(Color::VGA::BLACK) );

    double& radius();
    Point& center();
    Color& fill();

    bool inside(Point pt);
    Color test(Point pt);
    
    private:
    double m_radius;
    Point m_center;
    Color m_fill; //cambiar eventualmente a FILL
};

inline double pow2(double a);

#endif