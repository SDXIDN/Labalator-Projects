
#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;
const int n = 5;

int main()
{
	srand(time(NULL));
	int a[n][n];
	double x[n];

	for (int i = 0; i < n; i++) {

		cout << endl;

		for (int j = 0; j < n; j++) {

			a[i][j] = rand() % 50 - 25;
			cout << "  " << a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		int Pos1 = -1, Pos2 = -1;
		
		for (int j = 0; j < n; ++j) {
			if (a[i][j] > 0) {
				if (Pos1 == -1) {
					Pos1 = j;
				}
				Pos2 = j;
			}
		}
		
		
	
		
		if (Pos1 == -1 || Pos1 == Pos2) {
			x[i] = -1; 
			
		}else {
			x[i] = 0; 
			for (int j = Pos1; j <= Pos2; ++j) {
				x[i] += fabs(a[i][j]);
			}
		}
	}


    cout << "\n Масив X: ";
	for (int i = 0; i < n; ++i) {
	  cout << x[i] << " ";
	}
    cout << endl;

	return 0;


}



   