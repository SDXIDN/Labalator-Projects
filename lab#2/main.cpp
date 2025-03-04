#include <iostream>  
#include <string>  
#include <windows.h>
using namespace std;

class Race {
private:
    string route;
    string time;
public:
    Race() : route("Unknown"), time(0) {}
    Race(string a, string b) : route(a), time(b) {}

    void display() {
        cout << "Потяг: " << route << ", Час прибуття: " << time << "\n";
    }

    ~Race() {
        cout << "Race об'єкт знищено.\n";
    }
};

class Customer {
private:
    string name;
    int age;
public:
    Customer() : Customer("Unknown", 16) {}
    Customer(string c, int d) : name(c), age(d) {}

    void display() {
        cout << "Клієнт: " << name << ", Вік: " << age << "\n";
    }

    ~Customer() {
        cout << "Customer об'єкт знищено.\n";
    }
};

class Reservation {
private:
    Customer customer;
    Race race;
    string bookingDate;
public:
    Reservation() : customer(), race(), bookingDate("Unknown") {}
    Reservation(Customer c, Race r, string date) : customer(c), race(r), bookingDate(date) {}

    void display() {
        cout << "Бронювання: \n";
        customer.display();
        race.display();
        cout << "Дата бронювання: " << bookingDate << "\n";
    }

    ~Reservation() {
        cout << "Reservation об'єкт знищено.\n";
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Race race1("City-city", "20.30");
    race1.display();

    Customer customer1("Alex", 30);
    customer1.display();

    Reservation reservation1(customer1, race1, "2023-10-30");
    reservation1.display();

    return 0;
}
