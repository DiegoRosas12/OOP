#include "line.h"

Line::Line() {
    m_slope = 0.0;
    m_bias = 0.0;
}

Line::Line( Point pt0, Point pt1 ) : Line() {
    m_pt0 = pt0;
    m_pt1 = pt1;

    // denominador de la pendiente
    double denom = pt1.x - pt0.x;

    // pendiente
    if ( approx(denom, 0.0) ) m_slope = 1.0e8;
    else m_slope = (pt1.y - pt0.y)/denom;

    // desplazamiento
    m_bias = pt0.y - m_slope*pt0.x;
}

bool Line::intersection( const Line& ln ) {

    // CASO 1: líneas paralelas
    if ( approx(m_slope, ln.m_slope) ) return false;

    // encuentra el punto de intersección entre las rectas this y ln.
    Point pt = solve(ln);

    // verificar que el punto ipt se encuentre sobre ambos segmentos de recta
    if ( !intseg(pt, *this) ) return false;
    if ( !intseg(pt, ln) ) return false;
    return true;
}

double Line::slope() {
    return m_slope;
}

double Line::bias() {
    return m_bias;
}

Point Line::pt0() {
    return m_pt0;
}

Point Line::pt1() {
    return m_pt1;
}

Point Line::solve( const Line& ln ) {

    // punto de intersección
    Point pt;

    pt.x = (m_bias - ln.m_bias)/(ln.m_slope - m_slope);
    pt.y = m_slope*pt.x + m_bias;
    return pt;
}

bool Line::intseg( const Point& pt, const Line& ln ) {

    double x0 = min(ln.m_pt0.x, ln.m_pt1.x);
    double x1 = max(ln.m_pt0.x, ln.m_pt1.x);
    double y0 = min(ln.m_pt0.y, ln.m_pt1.y);
    double y1 = max(ln.m_pt0.y, ln.m_pt1.y);

    if ( !approx(x0, x1) )
        if ( pt.x < x0 || pt.x >= x1 ) return false;

    if ( !approx(y0, y1) )
        if ( pt.y < y0 || pt.y >= y1 ) return false;

    if ( approx(x0, x1) && approx(y0, y1) ) return false;

    return true;
}

bool Line::approx( double a, double b, double epsilon ) {

    double d = a - b;
    if ( d < 0.0 ) d = -d;
    if ( d < epsilon ) return true;
    return false;

    // double p;
    // if ( a < b ) p = (b-a)/b;
    // else p = (a-b)/a;

    // if ( p < epsilon ) return true;
    // return false;
}

inline double Line::min( double a, double b ) {
    if ( a < b ) return a;
    return b;
}

inline double Line::max( double a, double b ) {
    if ( a > b ) return a;
    return b;
}

