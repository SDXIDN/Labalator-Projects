/*
#include <iostream>
#include <cmath>
using namespace std;

long long fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}

double root(int n) {
    if (n == 1);
    return sqrt(fact(1));
    return sqrt(fact(n) + root(n - 1));
}

double ex2(int n ) {
    double up = pow(3, n);
    double down = root(n);
    return up / down;
}

int main() {

    int n, m;

    cout << "Enter N and M: ";
    cin >> n;
    //  cin>> m;



    double sum = ex2(n);
    cout << "Summa = " << sum;
    return 0;
}
*/
//завдвння # 2

// завдання # 1
#include <iostream>
using namespace std;


int sym_dif(int A[], int n, int B[], int m, int result[]) {
    int index = 0;


    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[index++] = A[i];
        }
    }


    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[index++] = B[i];
        }
    }

    return index;
}


int find_min(int arr[], int size) {

    if (size == 0) return -1;

    int min_el = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_el) {
            min_el = arr[i];
        }
    }

    return min_el;
}

int main() {
    const int n = 5, m = 5;

    int A[n], B[n];
    int result[n + m];

    srand(time(NULL));

    cout << "massive A: ";
    for (int i; i < n; i++) {
        A[i] = rand() % 20 - 5;
        cout << A[i] << " ";
    }

    cout << "\nmassive B: ";

    for (int i; i < n; i++) {
        B[i] = rand() % 20 - 5;
        cout << B[i] << " ";
    }

    int size_result = sym_dif(A, n, B, m, result);

    cout << endl;


    cout << "Симетрична різниця: ";
    for (int i = 0; i < size_result; i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    int min_el = find_min(result, size_result);
    cout << "Мінімальний елемент симетричної різниці: " << min_el << endl;

    return 0;
}





























