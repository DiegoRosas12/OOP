#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"
#include "color.h"
#include "shape.h"

class Circle : public Shape
{
public:
  Circle();
  Circle(Point center, double radius,
         Color fill = Color(Color::Name::BLACK));

  double &radius();
  Point &center();
  //Color &fill();

  bool inside(Point pt);
  // Color test(Point pt);

protected:
  double m_radius;
  Point m_center;
  //Color m_fill; // cambiar eventualmente a Fill m_fill;
};

//inline double pow2(double a);

#endif
