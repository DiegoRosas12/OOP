#include "circle.h"

Circle::Circle()
{
    m_radius = 0.0;
}

Circle::Circle(Point center, double radius, Color fill) : Circle()
{

    if (radius < 0.0)
        return;

    // define el bounding box
    m_bbox = Bbox(Point(center.x - radius, center.y - radius),
                  Point(center.x + radius, center.y + radius));
    m_radius = radius;
    m_center = center;
    m_fill = fill;
    // fill() = fill;
}

double &Circle::radius()
{
    return m_radius;
}

Point &Circle::center()
{
    return m_center;
}

// OVERRIDE
bool Circle::inside(Point pt)
{
    if (!m_bbox.test(pt))
        return false;
    double d;
    double x = pt.x - m_center.x;
    double y = pt.y - m_center.y;
    d = x * x + y * y; /* pow2(pt.x - m_center.x) + pow2(pt.y - m_center.y); */
    if (d <= m_radius * m_radius)
        return true;
    return false;
}

// OVERRIDE
Color Circle::test(Point pt)
{
    if (inside(pt))
    {
        return m_fill;
    }
    // return Color(); // CLEAR
    return Color::Name::CLEAR;
} 

/* inline double pow2(double a)
{
    return a * a;
} */
