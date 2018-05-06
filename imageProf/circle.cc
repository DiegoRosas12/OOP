#include "circle.h"


Circle::Circle() : Shape() {
    m_radius = 0.0;
}

Circle::Circle( Point center, double radius, Color fill ) : Circle() {

    if ( radius < 0.0 ) return;

    // define el bounding box
    m_bbox = Bbox( Point(center.x-radius, center.y-radius),
                   Point(center.x+radius, center.y+radius) );

    m_radius = radius;
    m_center = center;
    m_fill = fill;
}

double& Circle::radius() {
    return m_radius;
}

Point& Circle::center() {
    return m_center;
}

bool Circle::inside( Point& pt ) {

    // verifica que pt esté dentro del bbox
    if ( !m_bbox.test(pt) ) return false;

    double x = pt.x - m_center.x;
    double y = pt.y - m_center.y;
    double dd = x*x + y*y;

    if ( dd <= m_radius*m_radius ) return true;
    return false;
}

