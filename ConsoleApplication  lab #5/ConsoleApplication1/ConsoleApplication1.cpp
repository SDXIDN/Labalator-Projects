#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
const int n = 10;

int main()
{
    srand(time(NULL));
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int masA[n];
    int min1 = -1, min2 = -1, k, j;

    cout << " massive = { ";

    for (int i = 0; i < n; i++) {
        masA[i] = rand() % 20 - 3;
        cout << masA[i] << " ";

    }

    cout << "}";

    for (int i = 0; i < n; i++) {

        if (masA[i] < 0) {
            min1 = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {

        if (masA[i] < 0) {
            min2 = i;

        }
    }

    cout << "\n firstMIN 1 = index massive " << min1 << "\n lastMIN 2 = index massive " << min2 << endl;

    int dod = 1;

    if (min1 == -1) {
        cout << "\n В масиві немає від'ємних елементів." << endl;
        return(1);

    }
    else if (min1 == min2) {
        cout << "\n В масиві тільки один від'ємний елемент." << endl;
        return(2);
    }
    else if (min2 == -1) {
        cout << "\n В масиві тільки один від'ємний елемент." << endl;
        return(3);

    }
    else if (min1 + 1 == min2) {
        cout << "\n Перший і останній від'ємні елементи стоять поруч." << endl;
        return(4);

    }
    else {
        for (int i = min1 + 1; i < min2; i++) {

            dod *= masA[i];
        }
        cout << "\n dodanok = " << dod << endl;
    }

    cout << " Виводимо числа між першим та посліднім від'ємними чилами";

    for (int i = min1 + 1; i < min2; i++) {

        cout << " " << masA[i];
    }

    return (0);
}