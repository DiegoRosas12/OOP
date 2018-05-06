#ifndef _REGULAR_H_
#define _REGULAR_H_

#include "shape.h"
#include "poly.h"
#include "line.h"
#include <cmath>
#include <vector>

class Regular : public Shape {
    public:
    Regular();
    Regular(Point center, double radius, int sides, Color fill=Color(Color::Name::BLACK));
    bool inside(Point pt);
    Color test(Point pt);

    private:
    Point m_center;
    double m_radius;
    int m_sides;
    std::vector<Point> m_points;
    std::vector<Line> m_lines;
};

#endif