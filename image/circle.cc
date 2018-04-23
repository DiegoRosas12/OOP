#include "circle.h"

Circle::Circle(){
    m_radius = 0.0;
}
Circle::Circle(Point center, double radius, Color fill) : Circle() {
    if (radius < 0.0) return;

    m_bbox = Bbox(Point(center.x-radius, center.y-radius), Point(center.x+radius, center.y+radius));

    m_radius = radius;
    m_center = center;
    m_fill = fill;
}
double& Circle::radius(){
    return m_radius;
}
Point& Circle::center(){
    return m_center;
}
Color& Circle::fill(){
    return m_fill;
}
//OVERRIDE

bool Circle::inside(Point pt){
    double d;

    // verifica que pt esté dentro del bbox
    if ( !m_bbox.test(pt)) return false;
    d = pow2(pt.x - m_center.x) + pow2(pt.y - m_center.y);

    if (d <= pow2(m_radius)) return true;
    return false;
}
Color Circle::test(Point pt){
    if (inside(pt)) {
        return m_fill;
    }
        // return Color(); //CLEAR
        return Color::VGA::CLEAR;
}
inline double pow2(double a){
    return a*a;
}
