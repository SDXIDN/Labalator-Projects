
#include <iostream>
#include<ctime>
using namespace std;
int main() {
    srand(time(NULL));
    int n; 
    cout << "Enter array size (n < = 300):";
    cin >> n;

    if (n > 300 || n <= 0) {
        cout << "Invalid array size!";
        return 1;
    }

   
    int* X = new int[n];
    int* Y = new int[n];

 
    cout << "massive X[n]  ";
    for (int i = 0; i < n; i++) {
        X[i] = rand() % 20 - 10;
        cout << X[i] << " ";

    }
    cout << endl;
    cout << "massive Y[n]  ";
    for (int i = 0; i < n; i++) {
        Y[i] = rand() % 20 - 10;
        cout << Y[i] << " ";
    }
    

      
    int* Z = new int[2 * n];
    int z_size = 0; 

   
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < z_size; ++j) {
            if (Z[j] == X[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            Z[z_size++] = X[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < z_size; ++j) {
            if (Z[j] == Y[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            Z[z_size++] = Y[i];
        }
    }
    cout << endl;
  
    cout << "Merged Array Z: ";
    for (int i = 0; i < z_size; ++i) {
        cout << Z[i] << " ";
    }
    cout << endl;

 
    int sum = 0;
    for (int i = 0; i < z_size; ++i) {
        sum += Z[i];
    }

  
    cout << "Sum of elements Z: " << sum << std::endl;


    delete[] X;
    delete[] Y;
    delete[] Z;

    return 0;
}
