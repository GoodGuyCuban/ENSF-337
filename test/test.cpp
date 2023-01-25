
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main () {

    int j, *p1, **p2 ;

    p1 = &j;

    *p1 = 3;

    p2 = &p1;

    cout << p2;

    return 0;

}