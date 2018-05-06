#ifndef _POLY_H_
#define _POLY_H_

#include <vector>
#include "line.h"
#include "point.h"
#include "color.h"
#include "shape.h"

class Poly : public Shape {
    public:
        Poly();
        Poly( std::vector<Point> vert,
              Color fill = Color::Name::BLACK );

        Point vert( int index );

        bool inside( Point& pt );

    protected:
        std::vector<Line> m_side;
};

#endif

