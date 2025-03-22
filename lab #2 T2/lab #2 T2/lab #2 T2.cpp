#include <iostream>
#include <string>

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
        cout << "Train: " << route << ", Arrival time: " << timed << "\n";
    }

    Race operator+() const { return *this; }
    Race operator+(const Race& other) const { return Race(this->route + " & " + other.route, this->timed); }

    friend ostream& operator<<(ostream& os, const Race& race) {
        os << "Train: " << race.route << ", Arrival time: " << race.timed;
        return os;
    }

    friend istream& operator>>(istream& is, Race& race) {
        cout << "Enter a route: ";
        is >> race.route;
        cout << "Enter arrival time: ";
        is >> race.timed;
        return is;
    }

    ~Race() {
        raceCount--;
        cout << "Race object destroyed.\n";
    }
};

int Race::raceCount = 0;

class Person {
protected:
    string name;
    int age;

public:
    Person() : Person("Unknown", 16) {}
    Person(string c, int d) : name(c), age(d) {}
    Person(const Person& other) : name(other.name), age(other.age) {}
    Person(Person&& other) noexcept : name(move(other.name)), age(other.age) {}

    // Доданий оператор копіювання
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    void display() const {
        cout << "Client: " << name << ", Age: " << age << "\n";
    }

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Client: " << person.name << ", Age: " << person.age;
        return os;
    }

    friend istream& operator>>(istream& is, Person& person) {
        cout << "Enter customer name: ";
        is >> person.name;
        cout << "Enter age: ";
        is >> person.age;
        return is;
    }

    void showThis() const {
        cout << "Object address (this): " << this << endl;
    }

    virtual ~Person() {
        cout << "Person object destroyed.\n";
    }
};

class Customer : public Person {
private:
    string phoneNumber;
    int balance;

public:
    Customer() : Person(), phoneNumber("Unknown"), balance(0) {}
    Customer(string name, int age, string phone, int bal) : Person(name, age), phoneNumber(phone), balance(bal) {}

    Customer(const Customer& other) = default;  // Додаємо конструктор копіювання

    // Оператор присвоєння для копіювання
    Customer& operator=(const Customer& other) {  
        if (this != &other) { 
            Person::operator=(other);  
            phoneNumber = other.phoneNumber;  
            balance = other.balance;  
        }  
        return *this;
    }  

    // Оператор присвоєння для переміщення  
    Customer& operator=(Customer&& other) noexcept {  
        if (this != &other) { 
            Person::operator=(move(other)); 
            phoneNumber = move(other.phoneNumber);  
            balance = other.balance;
            other.balance = 0; 
        }  
        return *this; 
    }  
  
    void display() const {
        cout << "Client: " << name << ", Age: " << age << ", Phone: " << phoneNumber << ", Balance: " << balance << "\n";
    }

    friend ostream& operator<<(ostream& os, const Customer& customer) {
        os << "Client: " << customer.name << ", Age: " << customer.age << ", Phone: " << customer.phoneNumber << ", Balance: " << customer.balance;
        return os;
    }

    friend istream& operator>>(istream& is, Customer& customer) {
        cout << "Enter Client name: ";
        is >> customer.name;
        cout << "Enter age: ";
        is >> customer.age;
        cout << "Enter phone number: ";
        is >> customer.phoneNumber;
        cout << "Enter balance: ";
        is >> customer.balance;
        return is;
    }

    ~Customer() {
        cout << "Customer object destroyed.\n";
    }
};

class Reservation {
private:
    const Customer& customer;  // Використовуємо посилання на Customer
    Race race;
    string bookingDate;

public:
    Reservation(const Customer& c, Race r, string date) 
        : customer(c), race(r), bookingDate(date) {}

    void display() const {
        cout << "Booking: \n";
        customer.display();
        race.display();
        cout << "Booking date: " << bookingDate << "\n";
    }

    ~Reservation() {
        cout << "Reservation object destroyed.\n";
    }
};

int main() {
    Race race1("City-city", "20:30");
    race1.display();

    Customer customer1("Alex", 30, "123-456-789", 100);
    customer1.display();

    Reservation reservation1(customer1, race1, "2023-10-30");
    reservation1.display();

    cout << "Number of Race objects: " << Race::getRaceCount() << endl;

    Customer customer2("John", 25, "987-654-321", 200);
    customer2.display();
    customer2.showThis();

    return 0;
}
