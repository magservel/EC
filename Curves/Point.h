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
    /* Constructor */
    Point();
    Point (mpz_class x, mpz_class y);
    Point (mpz_class x, mpz_class y, Curve c);
    Point (mpz_class x, mpz_class y, Curve c, bool inf);
    Point (Curve c, bool inf);

    bool operator==(Point q);
    Point opposite();
    mpz_class div(mpz_class num, mpz_class den);
    Point add(Point q);
    Point multiply(mpz_class n);

    mpz_class x(void);
    mpz_class y(void);
    Curve c(void);
    bool inf(void);

private:
    mpz_class _x;
    mpz_class _y;
    Curve _c;
    bool _inf;
};



#endif //EC_POINT_H
