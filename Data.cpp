//
// Created by magali on 18/11/16.
//

#include "Data.h"

//using namespace std;

Data::Data(string file_path) {
    parser(file_path);
}
void Data::parser(string file_path) {
    string tp, tn, ta4, ta6, tr4, tr6, tgx, tgy, tr;
    string p, n, a4, a6, r4, r6, gx, gy, r;


    std::size_t pos;
    ifstream file(file_path);


    if (file) {
        cout << "Reading from the file" << endl;
        // Get p

        getline(file, tp);
        pos = tp.find("=");
        p = tp.substr((std::size_t)(pos+1));
        _p = mpz_class(p);
        // Get n
        getline(file, tn);
        pos = tn.find("=");
        n = tn.substr((std::size_t)(pos+1));
        _n = mpz_class(n);
        // Get a4
        getline(file, ta4);
        pos = ta4.find("=");
        a4 = ta4.substr((std::size_t)(pos+1));
        _a4 = mpz_class(a4);
        // Get a6
        getline(file, ta6);
        pos = ta6.find("=");
        a6 = ta6.substr((std::size_t)(pos+1));
        _a6 = mpz_class(a6);
        // Get r4
        getline(file, tr4);
        pos = tr4.find("=");
        r4 = tr4.substr((std::size_t)(pos+1));
        _r4 = mpz_class(r4);
        //Get r6
        getline(file, tr6);
        pos = tr6.find("=");
        r6 = tr6.substr((std::size_t)(pos+1));
        _r6 = mpz_class(r6);
        // Get gx
        getline(file, tgx);
        pos = tgx.find("=");
        gx = tgx.substr((std::size_t)(pos+1));
        _gx = mpz_class(gx);
        //Get gy
        getline(file, tgy);
        pos = tgy.find("=");
        gy = tgy.substr((std::size_t)(pos+1));
        _gy = mpz_class(gy);
        // Get r
        getline(file, tr);
        pos = tr.find("=");
        r = tr.substr((std::size_t)(pos+1));
        _r = mpz_class(r);

        file.close();


    } else cout << "Error while opening the file" <<endl;

}
void Data::print(){
    cout << "p: " << p().get_str() << endl;
    cout << "n: " << n().get_str() << endl;
    cout << "a4: " << a4().get_str() << endl;
    cout << "a6: " << a6().get_str() << endl;
    cout << "r4: " << r4().get_str() << endl;
    cout << "r6: " << r6().get_str() << endl;
    cout << "gx: " << gx().get_str() << endl;
    cout << "gy: " << gy().get_str() << endl;
    cout << "r: " << r().get_str() << endl;

}


mpz_class Data::p() {
    return _p;
}
mpz_class Data::n() {
    return _n;
}
mpz_class Data::a4() {
    return _a4;
}
mpz_class Data::a6() {
    return _a6;
}
mpz_class Data::r4() {
    return _r4;
}
mpz_class Data::r6() {
    return _r6;
}
mpz_class Data::gx() {
    return _gx;
}
mpz_class Data::gy() {
    return _gy;
}
mpz_class Data::r() {
    return _r;
}
