// ConsoleApplication lab #4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	double e, x, a;

	do {
		cout << "enter e ";
		cin >> e;
		cout << "enter x, a: ";
		cin >> x >> a;

	} while (x == 0 || a == 0 || e <= 0);

	//factorial повини дорівнювати 

	double sum = 0.0, k = 0, pow_X_k = 1, pow_a_4 = 1, dod, factorial = 1;

	dod = cos(pow_X_k) / (pow_a_4 + factorial);
	sum + dod;
	do {

		factorial *= k;
		pow_a_4 *= a * a * a * a;
		pow_X_k *= x;
		dod = cos(pow_X_k) / (pow_a_4 + factorial);
		sum += dod;
		k++;

	} while (fabs(dod) > e);





	cout << "dodanok = " << dod << "\nnumber = " << k << "\nsum value =" << sum;





	return(0);
}
