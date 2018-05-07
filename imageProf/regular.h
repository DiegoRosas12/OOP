#ifndef _REGULAR_H_
#define _REGULAR_H_

#include <vector>
#include <cmath>
#include "point.h"
#include "poly.h"

class Regular : public Shape {
    public:
        Regular();
        Regular( Point center, double radius, unsigned faces,
        Color fill = Color::Name::BLACK);

        double radius() const;
        unsigned faces() const;

        bool inside( Point& pt);
    protected:
        double m_radius;
        unsigned m_faces;
        Poly m_poly;
};

#endif