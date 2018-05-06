#ifndef _BOX_H__
#define _BOX_H__

#include "color.h"
#include "shape.h"
#include "point.h"

class Box : public Shape
{
public:
  Box();
  Box(Point topleft, Point bottomright,
      Color fill = Color::Name::BLUE);
  bool inside(Point &pt);
  Color test(Point &pt);

  // protected:
};

#endif