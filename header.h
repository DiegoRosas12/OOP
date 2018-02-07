//- header.h ------------------
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

int myfunction(int x, int y);

extern int Global; //Prototipo de variable global

#endif
//- header.c -----------------------
int myfunction(int x, int y) {
    return x+y;
}

/*
#if SISTOP == Windows
#include <conio.h>
#else
#include <unix.h>
#endif
*/