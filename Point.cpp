//
// Created by magali on 15/11/16.
//

#include "Point.h"
#include "Curve.h"

Point::Point() {
    _x = 0;
    _y = 0;
    _a4 = 0;
    _a6 = 0;
}

Point::Point (mpz_class x, mpz_class y) {
_x = x;
_y = y;

}

Point::Point (mpz_class x, mpz_class y, Curve c) {
_x = x;
_y = y;
_c = c;
}
bool Point::operator==(Point q) {
    return (_x == q.x() && _y == q.y());
}

Point Point::opposite(){
    return Point(_x, -_y);
}

Point Point::add(Point q) { //, mpz_class a1, mpz_class a2, mpz_class a3, mpz_class a4) {
    mpz_class L;
    if (_x != q.x()) L = (_y-q.y()) / (_x-q.x());
    else L = (3*sqrt(_x) + _a4) / (2*_y);

    mpz_class xr = sqrt(L) - _x - q.x();
    mpz_class yr = L*xr + L * _x - q.x();
    //        else L = (3*sqrt(_x) + 2*a2*_x + a4 - a1*_y)  /  (2*_y + a1*_x + a3);
    //        mpz_class xr = sqrt(L) + a1*L - a2 - _x - _x;
    //        mpz_class yr = -(L + a1)*xr + L * _x - q.x();
    return Point(xr, yr);
}

Point Point::multiply(mpz_class n) {
    if(n == 0) return Point();
    else if (n == 1) return Point(_x, _y);
    else if (n < 0) return multiply(-n);
    else if (n%2 == 0) return add(multiply(n/2).multiply(n/2));

    else return Point();
}

mpz_class Point::x(void) {
    return _x;
}

mpz_class Point::y(void) {
    return _y;
}

