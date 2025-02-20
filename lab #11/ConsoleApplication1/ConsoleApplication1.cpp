#include <iostream>
#include <cstring>

using namespace std;

// ���������� ��������� MARSHRUT
struct MARSHRUT {
    char startPoint[50];  // ���������� ����� ��������
    char endPoint[50];    // ʳ������ ����� ��������
    int routeNumber;      // ����� ��������
};

// ������� ��� ���������� �������� �� �������� (���������� ���������)
void sortRoutes(MARSHRUT routes[], int size) {
    for (int i = 1; i < size; i++) {
        MARSHRUT key = routes[i];
        int j = i - 1;

        // ���������� �� ������� ��������
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

    // �������� ����� ��� ��������
    cout << "������ ��� ��� " << SIZE << " ��������:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "������� " << i + 1 << endl;
        cout << "���������� �����: ";
        cin >> routes[i].startPoint;
        cout << "ʳ������ �����: ";
        cin >> routes[i].endPoint;
        cout << "����� ��������: ";
        cin >> routes[i].routeNumber;
    }

    // ���������� �������� �� ��������
    sortRoutes(routes, SIZE);

    // �������� ����� ������ ��� ������
    char searchPoint[50];
    cout << "\n������ ����� ������ ��� ������: ";
    cin >> searchPoint;

    // ����� ��������, �� ����������� ��� ����������� � ��������� �����
    bool found = false;
    cout << "\n��������, �� ����������� ��� ����������� � ����� " << searchPoint << ":" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(routes[i].startPoint, searchPoint) == 0 || strcmp(routes[i].endPoint, searchPoint) == 0) {
            cout << "����� ��������: " << routes[i].routeNumber
                << ", ���������� �����: " << routes[i].startPoint
                << ", ʳ������ �����: " << routes[i].endPoint << endl;
            found = true;
        }
    }

    // ��������� �����������, ���� �������� �� ��������
    if (!found) {
        cout << "�������� �� ��������, �� ����������� ��� ����������� � ����� " << searchPoint << "." << endl;
    }

    return 0;
}
