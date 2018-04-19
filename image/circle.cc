#include "circle.h"

Circle::Circle(){
    m_radius = 0.0;
}
Circle::Circle(Point center, double radius, Color fill) : Circle() {
    if (radius < 0.0) return;

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
bool Circle::inside(Point pt){
    double d;

    d = pow2(pt.x - m_center.x) + pow2(pt.y - m_center.y);

    if (d <= pow2(m_radius)) return true;
    return false;
}
Color Circle::test(Point pt){
    if (inside(pt)) {
        return m_fill;
    }
        return Color();
}
inline double pow2(double a){
    return a*a;
}
