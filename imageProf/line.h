#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include "point.h"

class Line {
    public:
        Line();
        Line( Point pt0, Point pt1 );

        bool intersection( const Line& ln );

        double slope();
        double bias();
        Point pt0();
        Point pt1();

    protected:
        Point m_pt0;
        Point m_pt1;
        double m_slope;
        double m_bias;

        Point solve( const Line& ln );
        bool intseg( const Point& pt, const Line& ln );

        inline bool approx( double a, double b, double epsilon = 1.0e-8 );

        inline double min( double a, double b );
        inline double max( double a, double b );
};

#endif

