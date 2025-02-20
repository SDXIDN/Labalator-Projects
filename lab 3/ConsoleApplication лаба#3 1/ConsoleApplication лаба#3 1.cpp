

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    double x, y, z;
    int k;
    cout << "Enter x, y, z, k \n";


    cin >> x;
    cin >> y;
    cin >> z;
    cin >> k;


    double v;

    switch (k)
    {
    case 1: v = pow(k, 2) * x + max(y, z);
        break;


    case 2: v = y / pow(k, 2) + max(x, z);
        break;


    case 3:v = z + k / min(x, y) + max(x, max(y, z));
        break;


    default:v = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        break;
    }


    cout << "\nv = " << v;
}


/*
//v=p якщо min(|x|,|y|,|z|)>x+y+z
//v=q якщо min(|x|,|y|,|z|)<=x+y+z

int main() {
    int x, y, z, v;

    bool p = true;
    bool q = false;

    cout << "Enter x, y, z\n ";

    cin >> x;
    cin >> y;
    cin >> z;


    if (min(fabs(x), min(fabs(y), fabs(z))) > x + y + z)
    {
        v = p;
        cout << " v = true ";
    }
    else if (min(fabs(x), min(fabs(y), fabs(z))) <= x + y + z)
    {
        v = q;
        cout << " v = false ";
    }

    cout << " x = " << x << " y = " << y << " z = " << z;


    return 0;
}
*/