#include "lineMy.h"

LineMy::LineMy(){
    clear();
}

LineMy::LineMy(Point a1, Point b1) : LineMy() {
    set(a1,b1);
}

bool LineMy::set(Point A1, Point B1){
    clear();
    if ( (A1.x == B1.x) && (A1.y == B1.y) ) return false;
    if (!isVertical()){
    a1 = A1;
    b1 = B1;
    m = ( A1.y - B1.y) / ( A1.x - B1.x );
    b = B1.y - m;
    return true;
    }else{
    x = A1.x;
    return true;
    }
}
bool LineMy::isVertical(){
    if (a1.x == b1.x){
        x = a1.x;
        return true;
    }else{
        return false;
    }
}

bool LineMy::isParallel(LineMy L1, LineMy L2){
    if ( L1.isVertical() && L2.isVertical()) {
        if (L1.x == L2.x) return false;
        return true;
    }else if (L1.isVertical() && !L2.isVertical()) {
        intersec.x = L1.x;
        intersec.y = (L1.x * L2.m) + L2.b;
    }else if (!L1.isVertical() && L2.isVertical()){
        intersec.x = L2.x;
        intersec.y = (L2.x * L1.m) + L1.b;
        return false;
    }else if (!L1. isVertical() && !L2.isVertical()){
        if (L1.m == L2.m) return true;
        intersec.x = (L2.b - L1.b) / (L1.m - L2.m);
        intersec.y = (L2.m*L1.b - L2.b*L1.m) / (L2.m - L1.m);
        return false;
    }
    return true;
}

bool LineMy::inter(Point& pt, LineMy L1, LineMy L2){
    if (isParallel(L1,L2)) {
        return false;
    }else{
        // Punto intersec ya se calculó en parallel
        if((L1.a1.x <= intersec.x <= L1.b1.x) && (L2.a1.x <= intersec.x <= L2.b1.x) && \
        (L1.a1.y <= intersec.y <= L1.b1.y) && (L2.a1.y <= intersec.y <= L2.b1.y)) return true;
        return false;    
    }
}

void LineMy::clear(){
    a1.x = 0;
    a1.y = 0;
    b1.x = 0;
    b1.y = 0;
    intersec.x = 0;
    intersec.y = 0;
    m = 0;
    b = 0;
    x = 0;
}