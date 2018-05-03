#ifndef _SHAPE_JS_
#define _SHAPE_JS_

#include "point.h"
#include "color.h"
#include "bbox.h"

class Shape
{
public:
  /*  Shape();
  Shape(Point center, Color fill,
        int vertx = 0, double inclination = 0);
  bool inside(Point pt); */
  Shape();
  virtual ~Shape();
  Color &fill();

  Bbox& bbox();
  virtual bool inside(Point &pt) = 0; //makes abstract class
  Color test(Point pt);  
  Color test(Point& pt);

protected:
  /* int vertx;
  double inclination;
  Point center;
  Color fill; */
  Color m_fill;
  Bbox m_bbox;
};

#endif