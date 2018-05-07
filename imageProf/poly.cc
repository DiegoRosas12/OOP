#include "poly.h"

Poly::Poly() { }

Poly::Poly( std::vector<Point> vert, Color fill ) : Poly() {
    double min_x, min_y, max_x, max_y;

    const double d = 0.0001;

    // inicialización de min/max (deben ser valores en vert)
    min_x = vert[0].x;
    max_x = vert[0].x;
    min_y = vert[0].y;
    max_y = vert[0].y;

    // buscamos el máximo y el mínimo
    for ( unsigned i=1; i<vert.size(); i++ ) {
        if ( vert[i].x > max_x ) max_x = vert[i].x;
        if ( vert[i].x < min_x ) min_x = vert[i].x;
        if ( vert[i].y > max_y ) max_y = vert[i].y;
        if ( vert[i].y < min_y ) min_y = vert[i].y;
    }

    // bounding box ligeramente más grande
    m_bbox = Bbox( Point(min_x-d,min_y-d), Point(max_x+d,max_y+d) );

    for ( unsigned i=0; i<vert.size()-1; i++ ) {
        m_side.push_back( Line(vert[i], vert[i+1]) );
    }
    m_side.push_back( Line(vert.back(), vert.front()) );

    m_fill = fill;
}

Point Poly::vert( int index ) {
    return m_side[index].pt0();
}

bool Poly::inside( Point& pt ) {

   // verifica que pt esté dentro del bbox
   if ( !m_bbox.test(pt) ){
       return false;
   } 

   int count = 0;
   Point cc = m_bbox.topleft();
//    cc.x -= 1.0;
//    cc.y -= 2.0;
   
   Line test = Line(cc, pt);

   for ( auto ln : m_side ) {
       if ( test.intersection(ln) ) count ++;
   }

   if ( count & 1 ) return true;
   return false;
}

