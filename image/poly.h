#ifndef _POLY_H_
#define _POLY_H_

#include "shape.h"
#include <vector>

class Poly : public Shape
{
  public:
    Poly();
    Poly(std::vector<Point> vertices,
         Color fill = Color::Name::BLACK);
        
    bool inside(Point &pt);

  private:
    std::vector<Point> m_vertices;
};

#endif