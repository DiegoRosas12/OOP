#include "bbox.h"

Bbox::Bbox() {}

Bbox::Bbox(Point topleft, Point bottomright)
{
    set(topleft, bottomright);
}

bool Bbox::set(Point topleft, Point bottomright)
{
    if (topleft.x > bottomright.x)
    {
        return false;
    }
    if (topleft.y > bottomright.y)
    {
        return false;
    }

    m_topleft = topleft;
    m_bottomright = bottomright;

    return true;
}

Point Bbox::topleft()
{
    return m_topleft;
}

Point Bbox::bottomright()
{
    return m_bottomright;
}

bool Bbox::test(Point pt)
{
    if (pt.x < m_topleft.x)
        return false;
    if (pt.x > m_bottomright.x)
        return false;
    if (pt.y < m_topleft.y)
        return false;
    if (pt.y > m_bottomright.y)
        return false;
    return true;
}