//
// Created by magali on 15/11/16.
//



#ifndef EC_POINT_H
#define EC_POINT_H

#include <iostream>
#include <gmpxx.h>
#include "Curve.h"

using namespace std;


class Point {

public:
    Point();
    Point (mpz_class x, mpz_class y, Curve c, bool inf);
    bool operator==(Point q);
    Point opposite();
    Point add(Point q);
    Point multiply(mpz_class n);
    mpz_class x(void);
    mpz_class y(void);

private:
    mpz_class _x;
    mpz_class _y;
    Curve _c;
    bool _inf;


};



#endif //EC_POINT_H
