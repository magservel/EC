//
// Created by magali on 15/11/16.
//

#include "Point.h"

Point::Point() {
    _x = mpz_class(0);
    _y = mpz_class(0);
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
    _x = mpz_class(0);
    if (inf) _y = mpz_class(1); else _y = mpz_class(0);
    _c = c;
    _inf = inf;
}

bool Point::operator==(Point q) {
    return (_x == q.x() && _y == q.y());
}
bool Point::equal(Point q) {
    return (_x == q.x() && _y == q.y());
}

Point Point::opposite(){
    return Point(_x, (_x +_y) % _c.p(), _c);
}
bool Point::isOpposite(Point q) {
    return (opposite().equal(q));
}

mpz_class Point::modInverse(mpz_class k, mpz_class p) {
    mpz_class b0(p), t, q;
    mpz_class x0 (0), x1(1);
    if (p == mpz_class(1)) return mpz_class(1);
    while (k > mpz_class(1)) {
            q = k / p;
            t = p, p = k % p, k = t;
            t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < mpz_class(0)) x1 += b0;
    return x1;
}
mpz_class Point::div(mpz_class num, mpz_class den) {
    return (num * modInverse(den, _c.p())) % _c.p();
}

Point Point::doubl() {
    mpz_class L(0), v(0), x(0), y(0), tmp(0);
    if (_y == 0) {
        return Point(_c, true);
    } else {
        L = div(3*sqrt(_x) + _c.a4(), 2*_y); // TODO : Add modulo
        mpz_pow_ui(tmp.get_mpz_t(), _x.get_mpz_t(), 3);
        v = div(-tmp + _c.a4()*_x + 2*_c.a6(), 2*_y);// TODO : Add modulo
        x = (sqrt(L) - 2*_x) % _c.p();
        mpz_pow_ui(tmp.get_mpz_t(), L.get_mpz_t(), 3);
        y = (-tmp + L*(2*_x)) % _c.p();
        return Point(x, y, _c, _inf);
    }
}
Point Point::add_distinct(Point q) {
    mpz_class L(0), v(0), x(0), y(0), tmp(0);
    Point p(_x, _y, _c, _inf);

    if (p.x() == q.x()) {
        return Point(_c, true);
    } else {
        L = div(q.y() - p.y(), q.x() - p.x()); // TODO : Add modulo
        v = div((p.y() * q.x() - q.y() * p.x()), q.x() - p.x());// TODO : Add modulo
        x = (sqrt(L) - p.x() - q.x()) % _c.p();
        mpz_pow_ui(tmp.get_mpz_t(), L.get_mpz_t(), 3);
        y = (-tmp + L * (p.x() + q.x())) % _c.p();
        return Point(x, y, _c);
    }
}
Point Point::add(Point q) {
    Point p(_x, _y, _c, _inf);
    if (p.inf()) {       // P=O || Q=0
        return q;
    } else if (q.inf()){
        return p;
    } else if(p.isOpposite(q)) { // P = -Q
        return Point(_c, true);
    } else if (p == q) {
        return doubl();
    } else return add_distinct(q);
}


Point Point::multiply(mpz_class k) {

    if (k == _c.n()) return Point (_c, true);

    string bin = k.get_str(2);
    Point p(_x, _y, _c, _inf), q(_c, true);
    for(int i = 0; i < bin.length(); i++) {
        q = q.doubl();
        if (bin[i] == '1') {
            q = q.add(p);
        }
    }
    return q;


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

void Point::print(string name){
    cout << name << endl;
    cout << "x: " << x().get_str(10) << endl;
    cout << "y: " << y().get_str(10) << endl;

}
