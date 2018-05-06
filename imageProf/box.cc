#include "box.h"


Box::Box() { }

Box::Box( Point topleft, Point bottomright, Color fill ) {

    // definimos el bbox, igual que la caja
    m_bbox.set( topleft, bottomright );

    // deinimos el color de relleno
    m_fill = fill;
}

bool Box::inside( Point& pt ) {

    // verifica si el punto se encuentra dentro del bbox
    if ( m_bbox.test(pt) ) return true;
    return false;
}

