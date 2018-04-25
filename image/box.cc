#include "box.h"

Box::Box()
{
}

Box::Box(Point topleft, Point bottomright, Color fill)
{
    // definimos el bbox, igual que la caja
    //m_bbox = Bbox(topleft, bottomright);
    m_bbox.set(topleft, bottomright);
    // definimos el color del relleno
    m_fill = fill;
}

bool Box::inside(Point &pt)
{
    if (m_bbox.test(pt))
        return true;
    return false;
}

/* Color Box::test(Point &pt)
{
    if (inside(pt))
    {
        return m_fill;
    }
    // return Color(); // CLEAR
    return Color::Name::CLEAR;
} */