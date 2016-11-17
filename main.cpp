#include <iostream>
#include <fstream>
#include <string>
#include <gmpxx.h>

#include "Point.h"

using namespace std;

void parser(void);

int main() {

//     mpz_ptr t;
//   mpz_class __p, __n, __a4, __a6, __r4, __r6, __gx, __gy, __r;
//    mpz_ptr t;


    /*PARSER*/
    string p, _p;

    std::size_t pos;
    ifstream file("/home/magali/ClionProjects/EC/elliptic_curves/Weierstrass/cw256/w256-001.gp");


    getline(file, p);
    pos = p.find("=");
    _p = p.substr((std::size_t)(pos+1));
    //int result = mpz_set_str(t, _p, 10);

    mpz_class test (_p);
    cout << test.get_str() << endl;



    return 0;
}

void parser(void){
    string p, n, a4, a6, r4, r6, gx, gy, r;
    string _p, _n, _a4, _a6, _r4, _r6, _gx, _gy, _r;



    std::size_t pos;
    ifstream file("/home/magali/ClionProjects/EC/elliptic_curves/Weierstrass/cw256/w256-001.gp");


    if (file) {
        cout << "Reading from the file" << endl;
        // Get p
        getline(file, p);
        pos = p.find("=");
        _p = p.substr((std::size_t)(pos+1));
        cout << p << endl;
        cout << _p << endl;
        // Get n
        getline(file, n);
        pos = n.find("=");
        _n = n.substr((std::size_t)(pos+1));
        cout << n << endl;
        cout << _n << endl;


        getline(file, a4);
        pos = a4.find("=");
        _a4 = a4.substr((std::size_t)(pos+1));
        cout << a4 << endl;
        cout << _a4 << endl;


        getline(file, a6);
        pos = a6.find("=");
        _a6 = a6.substr((std::size_t)(pos+1));
        cout << a6 << endl;
        cout << _a6 << endl;


        getline(file, r4);
        pos = r4.find("=");
        _r4 = r4.substr((std::size_t)(pos+1));
        cout << r4 << endl;
        cout << _r4 << endl;


        getline(file, r6);
        pos = r6.find("=");
        _r6 = r6.substr((std::size_t)(pos+1));
        cout << r6 << endl;
        cout << _r6 << endl;


        getline(file, gx);
        pos = gx.find("=");
        _gx = gx.substr((std::size_t)(pos+1));
        cout << gx << endl;
        cout << _gx << endl;


        getline(file, gy);
        pos = gy.find("=");
        _gy = gy.substr((std::size_t)(pos+1));
        cout << gy << endl;
        cout << _gy << endl;

        getline(file, r);
        pos = r.find("=");
        _r = r.substr((std::size_t)(pos+1));
        cout << r << endl;
        cout << _r << endl;


        file.close();


    } else cout << "Error while opening the file" <<endl;

}