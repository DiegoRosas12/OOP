#include "line.h"


Line::Line() { }

Line::Line( Point pt0, Point pt1 ) : Line() {
    m_pt0 = pt0;
    m_pt1 = pt1;

    // denominador de la pendiente
    m_denom = pt1.x - pt0.x;

    // pendiente
    m_slope = (pt1.y - pt0.y)/m_denom;

    // desplazamiento
    m_bias = pt0.y - m_slope*pt0.x;
}

bool Line::intersection( Point& pt, const Line& ln ) {

    // CASO 1: líneas paralelas
    if ( m_slope == ln.m_slope ) return false;

    // encuentra el punto de intersección entre las rectas this y ln.
    Point ipt = solve(ln);

    // verificar que el punto ipt se encuentre sobre ambos segmentos de recta
    if ( !intseg(ipt, *this) ) return false;
    if ( !intseg(ipt, ln) ) return false;

    // cambia la referencia por el punto de intersección
    pt = ipt;
    return true;
}

double Line::slope() {
    return m_slope;
}

double Line::bias() {
    return m_bias;
}

Point Line::point( int index ) {
    if ( index == 0 ) return m_pt0;
    if ( index == 1 ) return m_pt1;
    return Point();
}

Point Line::solve( const Line& ln ) {

    // punto de intersección
    Point ipt;

    // CASO 2: this con pendiente infinita, ln con pendiente finita
    if ( m_denom == 0.0 && ln.m_denom != 0.0 ) {
        ipt.x = m_pt0.x;
        ipt.y = ln.m_slope*ipt.x + ln.m_bias;
    }

    // CASO 3: this con pendiente finita, ln con pendiente infinita
    if ( m_denom != 0.0 && ln.m_denom == 0.0 ) {
        ipt.x = ln.m_pt0.x;
        ipt.y = m_slope*ipt.x + m_bias;
    }

    // CASO 4: todas las pendientes finitas
    if ( m_denom != 0.0 && ln.m_denom != 0.0 ) {
        ipt.x = (m_bias - ln.m_bias)/(ln.m_slope - m_slope);
        ipt.y = m_slope*ipt.x + m_bias;
    }

    return ipt;
}

bool Line::intseg( const Point& pt, const Line& ln ) {

    // asigna a x0 la coordenada x mínima, y a x1 la máxima
    double x0, x1;
    if ( ln.m_pt0.x <= ln.m_pt1.x ) {
        x0 = ln.m_pt0.x;
        x1 = ln.m_pt1.x;
    }
    else {
        x0 = ln.m_pt1.x;
        x1 = ln.m_pt0.x;
    }

    // asigna a y0 la coordenada y mínima, y a y1 la máxima
    double y0, y1;
    if ( ln.m_pt0.y <= ln.m_pt1.y ) {
        y0 = ln.m_pt0.y;
        y1 = ln.m_pt1.y;
    }
    else {
        y0 = ln.m_pt1.y;
        y1 = ln.m_pt0.y;
    }

    // conprueba que el punto esté dentro de las coordenadas
    if ( pt.x < x0 || pt.x > x1 ) return false;
    if ( pt.y < y0 || pt.y > y1 ) return false;
    return true;
}
// contruye una linea
Line Line::set(Line& ln,  Point pt0, Point pt1 ) {
    ln.m_pt0 = pt0;
    ln.m_pt1 = pt1;

    // denominador de la pendiente
    ln.m_denom = pt1.x - pt0.x;

    // pendiente
    ln.m_slope = (pt1.y - pt0.y)/m_denom;

    // desplazamiento
    ln.m_bias = pt0.y - m_slope*pt0.x;

    return ln;
}

