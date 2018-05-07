#include "shape.h"

Shape::Shape() { }

Shape::~Shape() { }

void Shape::set_fill(Color fill) {
    m_fill = fill;
}

Color Shape::get_fill() const {
    return m_fill;
}

Bbox Shape::get_bbox() const {
    return m_bbox;
}

// trabaja con una copia de pt
// útil para definir pt con un constructor directamente
Color Shape::test( Point pt ) {
    if ( inside(pt) ) return m_fill;
    return Color::Name::CLEAR;
}


// trabaja con una referencia a pt
// útil si ya se tiene pt como objeto
Color Shape::test( Point& pt ) {
    if ( inside(pt) ) return m_fill;
    return Color::Name::CLEAR;
}

