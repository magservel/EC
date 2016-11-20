//
// Created by magali on 15/11/16.
//

#include "Point.h"

Point::Point() {
    _x = 0;
    _y = 0;
    _c = Curve();
    _inf = false;
}
Point::Point (mpz_class x, mpz_class y) {
    _x = x;
    _y = y;
    _c = Curve();
    _inf = false;

}
Point::Point (mpz_class x, mpz_class y, Curve c) {
    _x = x;
    _y = y;
    _c = c;
    _inf = false;
}
Point::Point (mpz_class x, mpz_class y, Curve c, bool inf) {
    _x = x;
    _y = y;
    _c = c;
    _inf = inf;
}
Point::Point (Curve c, bool inf) {
    _x = 0;
    _y = 0;
    _c = c;
    _inf = true;
}

bool Point::operator==(Point q) {
    return (_x == q.x() && _y == q.y());
}

Point Point::opposite(){
    return Point(_x, _x +_y);
}
mpz_class Point::div(mpz_class num, mpz_class den) {
    mpz_class r(0);
    return r;
} // TODO: div

Point Point::add(Point q) { //, mpz_class a1, mpz_class a2, mpz_class a3, mpz_class a4) {
    Point p(_x, _y, _c, _inf);
    mpz_class L(0), v(0), x(0), y(0);
    if (p.inf() || q.inf()) {
        return Point(_c, true);
    } else if(q == p.opposite()) {
        return Point(_c, true);
    } else if (p == q && _y == 0) {
        return Point(_c, true);
    } else if (p.x() == q.x() && p.y()!= q.y()) {
        L = div(q.y() - p.y(), q.x() - p.x()); // TODO : Add modulo
        v = div((p.y()*q.x() - q.y()*p.x()), q.x() - p.x());// TODO : Add modulo
        x = L*L - p.x() - q.x();
        y = -L*L*L + L*(p.x() + q.x());
        return Point(x, y, _c);
    } else {
        L = div(3*_x*_x + _c.a4(), 2*_y); // TODO : Add modulo
        v = div(-_x*_x*_x + _c.a4()*_x + 2*_c.a6(), 2*_y);// TODO : Add modulo
        x = L*L - p.x() - q.x();
        y = -L*L*L + L*(p.x() + q.x());
        return Point(x, y, _c);

    }

}


Point Point::multiply(mpz_class k) { // TODO: div
    if (k == _c.n()) return Point (_c, true);

    string bin = k.get_str(2);
    Point p(_c, false);

    for(int i = 0; i < bin.length(); i++) {


    }

}


mpz_class Point::x(void) {
    return _x;
}
mpz_class Point::y(void) {
    return _y;
}
Curve Point::c(void) {
    return _c;
}
bool Point::inf(void) {
    return _inf;
}


