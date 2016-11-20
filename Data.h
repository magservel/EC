//
// Created by magali on 18/11/16.
//

#ifndef EC_DATA_H
#define EC_DATA_H

#include <iostream>
#include <fstream>
#include <gmpxx.h>

using namespace std;

class Data {

public:

    Data(string file_path);
    void parser(string file_path);
    void print();

    mpz_class p();
    mpz_class n();
    mpz_class a4();
    mpz_class a6();
    mpz_class gx();
    mpz_class gy();
    mpz_class r4();
    mpz_class r6();
    mpz_class r();

private:
    mpz_class _p;
    mpz_class _n;
    mpz_class _a4;
    mpz_class _a6;
    mpz_class _r4;
    mpz_class _r6;
    mpz_class _gx;
    mpz_class _gy;
    mpz_class _r;

};


#endif //EC_DATA_H
