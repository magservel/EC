//
// Created by magali on 15/11/16.
//

#ifndef EC_CURVE_H
#define EC_CURVE_H


#include <gmpxx.h>

class Curve {

public:

    /* Constructor */
    Curve (void);
    Curve (mpz_class p, mpz_class n, mpz_class a4, mpz_class a6);
    Curve (char* size, char* nb);

    /* Accessor */
    mpz_class p();
    mpz_class n();
    mpz_class a4();
    mpz_class a6();

    void setCurve(char* dir, char* name);


private:
    mpz_class _p;
    mpz_class _n;
    mpz_class _a4;
    mpz_class _a6;

};


#endif //EC_CURVE_H
