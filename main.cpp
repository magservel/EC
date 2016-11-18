#include <iostream>
#include <gmpxx.h>

#include "Point.h"
#include "Data.h"

using namespace std;

int main() {

    string name = "w256-001.gp";
    string dir = "cw256";
    string path = "/home/magali/ClionProjects/EC/elliptic_curves/Weierstrass/";
    string file_path = path + dir + "/" + name;

    Data data (file_path);
    //data.print();


    return 0;
}
