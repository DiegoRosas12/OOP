#include "shape.h"

Shape::Shape() {}
Shape::~Shape() {

}

Bbox& 

bool Shape::inside(Point &pt)
{
    return false;
}

Color& Shape::fill()
{
    return m_fill;
}

Color Shape::test(Point &pt)
{
    if (inside(pt))
    {
        return m_fill;
    }
    // return Color(); // CLEAR
    return Color::Name::CLEAR;
}