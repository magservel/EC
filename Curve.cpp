//
// Created by magali on 15/11/16.
//

#include "Curve.h"


Curve::Curve (void) {
    _p = 0;
    _n = 0;
    _a4 = 0;
    _a6 = 0;
}
Curve::Curve (mpz_class p, mpz_class n, mpz_class a4, mpz_class a6) {
    _p = p;
    _n = n;
    _a4 = a4;
    _a6 = a6;

}


/* Accessor */
mpz_class Curve::p(){
    return _p;
}
mpz_class Curve::n(){
    return _n;
}
mpz_class Curve::a4(){
    return _a4;
}
mpz_class Curve::a6(){
    return _a6;
}
