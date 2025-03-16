#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Race {
private:
    string route;
    string timed;
    static int raceCount;  

public:
   
    Race() : route("Unknown"), timed("00:00") { raceCount++; }
    Race(string a, string b) : route(a), timed(b) { raceCount++; }

    Race(const Race& other) : route(other.route), timed(other.timed) { raceCount++; }

    Race(Race&& other) noexcept : route(move(other.route)), timed(move(other.timed)) { raceCount++; }

  
    static int getRaceCount() { return raceCount; }

   
    void display() const {
        cout << "Потяг: " << route << ", Час прибуття: " << timed << "\n";
    }

    
    Race operator+() const { return *this; }
    Race operator+(const Race& other) const { return Race(this->route + " & " + other.route, this->timed); }

  
    friend ostream& operator<<(ostream& os, const Race& race) {
        os << "Потяг: " << race.route << ", Час прибуття: " << race.timed;
        return os;
    }

    friend istream& operator>>(istream& is, Race& race) {
        cout << "Введіть маршрут: ";
        is >> race.route;
        cout << "Введіть час прибуття: ";
        is >> race.timed;
        return is;
    }

   
    ~Race() {
        raceCount--;
        cout << "Race об'єкт знищено.\n";
    }
};


int Race::raceCount = 0;


class Customer {
private:
    string name;
    int age;

public:
    
    Customer() : Customer("Unknown", 16) {}
    Customer(string c, int d) : name(c), age(d) {}

    Customer(const Customer& other) : name(other.name), age(other.age) {}

    Customer(Customer&& other) noexcept : name(move(other.name)), age(other.age) {}

    void display() const {
        cout << "Клієнт: " << name << ", Вік: " << age << "\n";
    }

    friend ostream& operator<<(ostream& os, const Customer& customer) {
        os << "Клієнт: " << customer.name << ", Вік: " << customer.age;
        return os;
    }

    friend istream& operator>>(istream& is, Customer& customer) {
        cout << "Введіть ім'я клієнта: ";
        is >> customer.name;
        cout << "Введіть вік: ";
        is >> customer.age;
        return is;
    }

    void showThis() const {
        cout << "Адреса об'єкта Customer (this): " << this << endl;
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

    Reservation(const Reservation& other) : customer(other.customer), race(other.race), bookingDate(other.bookingDate) {}

    Reservation(Reservation&& other) noexcept : customer(move(other.customer)), race(move(other.race)), bookingDate(move(other.bookingDate)) {}

    void display() const {
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
    
    
    
    Race race1("City-city", "20:30");
    race1.display();

    Customer customer1("Alex", 30);
    customer1.display();

    Reservation reservation1(customer1, race1, "2023-10-30");
    reservation1.display();

    cout << "Кількість об'єктів Race: " << Race::getRaceCount() << endl;

    Customer customer2("John", 25);
    customer2.display();
    customer2.showThis();

    Race race2;
    cin >> race2;
    cout << race2 << endl;

    return 0;
}
