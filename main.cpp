#include <iostream>
#include <gmpxx.h>

#include "Curves/Point.h"
#include "Curves/Curve.h"
#include "Data.h"

using namespace std;

int main() {

    string name = "w256-001.gp";
    string dir = "cw256";
    string path = "/home/magali/ClionProjects/EC/elliptic_curves/Weierstrass/";
    string file_path = path + dir + "/" + name;

    Data data (file_path);
    //data.print();


    Curve c(data.p(), data.n(), data.a4(), data.a6());
    Point p(data.gx(), data.gy(), c, false);


    Point q = p.multiply(mpz_class("1"));

    p.print("p");
    q.print("q");

    return 0;
}
