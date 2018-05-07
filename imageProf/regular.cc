#include "regular.h"
Regular::Regular(){
    m_radius = 0;
    m_faces = 0;
}
Regular::Regular( Point center, double radius, unsigned faces,
Color fill) : Regular(){
    if (radius < 0.0) return;
    if ( faces < 3) return;

    m_radius = radius;
    m_faces = faces;

    // calculo de los vertices del poligono
    double u = 2.0 * M_PI/faces;

    double ang;
    Point pt;
    std::vector<Point> vert;

    for (unsigned i=0; i<faces; i++){
        ang = u*i;
        pt.x = radius*std::cos(ang) + center.x;
        pt.y = radius*std::sin(ang) + center.y;

        vert.push_back(pt);
    }

    m_poly = Poly(vert);

    m_bbox = m_poly.bbox();

    m_fill = fill;

}

double Regular::radius() const {
    return m_radius;
}
unsigned Regular::faces() const{
    return m_faces;
}

bool Regular::inside( Point& pt){
    return m_poly.inside(pt);
}