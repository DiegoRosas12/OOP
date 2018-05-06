#ifndef _BBOX_H_
#define _BBOX_H_

#include "point.h"

class Bbox
{
public:
  Bbox();
  Bbox(Point topleft, Point bottomright);
  bool set(Point topleft, Point bottomright);
  Point topleft();
  Point bottomright();
  bool test(Point pt);

protected:
  Point m_topleft, m_bottomright;
};

#endif