#include <iostream>
#include <cstring>

using namespace std;

// Оголошення структури MARSHRUT
struct MARSHRUT {
    char startPoint[50];  // Початковий пункт маршруту
    char endPoint[50];    // Кінцевий пункт маршруту
    int routeNumber;      // Номер маршруту
};

// Функція для сортування маршрутів за номерами (сортування вставками)
void sortRoutes(MARSHRUT routes[], int size) {
    for (int i = 1; i < size; i++) {
        MARSHRUT key = routes[i];
        int j = i - 1;

        // Сортування за номером маршруту
        while (j >= 0 && routes[j].routeNumber > key.routeNumber) {
            routes[j + 1] = routes[j];
            j--;
        }
        routes[j + 1] = key;
    }
}

int main() {
    const int SIZE = 4;
    MARSHRUT routes[SIZE];

    // Введення даних про маршрути
    cout << "Введіть дані для " << SIZE << " маршрутів:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Маршрут " << i + 1 << endl;
        cout << "Початковий пункт: ";
        cin >> routes[i].startPoint;
        cout << "Кінцевий пункт: ";
        cin >> routes[i].endPoint;
        cout << "Номер маршруту: ";
        cin >> routes[i].routeNumber;
    }

    // Сортування маршрутів за номерами
    sortRoutes(routes, SIZE);

    // Введення назви пункту для пошуку
    char searchPoint[50];
    cout << "\nВведіть назву пункту для пошуку: ";
    cin >> searchPoint;

    // Пошук маршрутів, що починаються або закінчуються у введеному пункті
    bool found = false;
    cout << "\nМаршрути, які починаються або закінчуються в пункті " << searchPoint << ":" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(routes[i].startPoint, searchPoint) == 0 || strcmp(routes[i].endPoint, searchPoint) == 0) {
            cout << "Номер маршруту: " << routes[i].routeNumber
                << ", Початковий пункт: " << routes[i].startPoint
                << ", Кінцевий пункт: " << routes[i].endPoint << endl;
            found = true;
        }
    }

    // Виведення повідомлення, якщо маршрути не знайдено
    if (!found) {
        cout << "Маршрути не знайдено, які починаються або закінчуються в пункті " << searchPoint << "." << endl;
    }

    return 0;
}
