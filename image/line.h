#ifndef _LINE_H_
#define _LINE_H_

#include "point.h"

class Line {
    public:
        Line();
        Line( Point pt0, Point pt1 );

        bool intersection( Point& pt, const Line& ln );

        double slope();
        double bias();
        Point point( int index );

        Line set(Line& ln, Point pt0, Point pt1);

    private:
        Point m_pt0;
        Point m_pt1;
        double m_denom;
        double m_slope;
        double m_bias;

        Point solve( const Line& ln );
        bool intseg( const Point& pt, const Line& ln );
};

#endif

