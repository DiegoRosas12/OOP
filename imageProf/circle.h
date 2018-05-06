#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"
#include "color.h"
#include "shape.h"

class Circle : public Shape {
  public:
    Circle();
    Circle( Point center, double radius,
            Color fill=Color::Name::BLACK );

    double& radius();
    Point& center();

    bool inside( Point& pt );

  protected:
    double m_radius;
    Point  m_center;
};

#endif

