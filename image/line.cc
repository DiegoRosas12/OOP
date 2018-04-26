#include "line.h"

Line::Line(){
    clear();
}

Line::Line(Point a1, Point b1) : Line() {
    //clear();
    set(a1,b1);
}
// Ambiguedad en estos nombres
bool Line::set(Point A1, Point B1){
    clear();
    if (!isVertical()){
    a1 = A1;
    b1 = B1;
    m = ( A1.y - B1.y) / ( A1.x - B1.x );
    b = B1.y - m;
    }else{
    x = A1.x;
    return true;
    }
}
bool Line::isVertical(){
    if (a1.x == b1.x){
        x = a1.x;
        return true;
    }else{
        return false;
    }
}

bool Line::isParallel(Line L1, Line L2){
    if ( L1.isVertical() && L2.isVertical()) {
         if (L1.x == L2.x) return false;
         return true;
    }else if (L1.isVertical() && !L2.isVertical()) {
        intersec.x = L1.x;
        intersec.y = (L1.x * L2.m) + L2.b;
        return false;
    }else if (!L1.isVertical() && L2.isVertical()){
        intersec.x = L2.x;
        intersec.y = (L2.x * L1.m) + L1.b;
        return false;
    }else if (!L1. isVertical() && !L2.isVertical()){
        if (L1.m == L2.m) return true;
        intersec.x = (L2.b - L1.b) / (L1.m - L2.m);
        intersec.y = (L2.m*L1.b - L2.b*L1.m) / (L2.m - L1.m);
    }
}

bool Line::inter(Line L1, Line L2){
    if (isParallel(L1,L2)) {
        return false;
    }else{
        // hacer caso con recta vertical
        intersec.x = (L2.b - L1.b) / (L1.m - L2.m);
        return true;
    }
}


void Line::clear(){
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