#include <iostream>
#include <string>
using namespace std;



class IPrintable {
public:
    virtual void display() const = 0;
    virtual void printInfo() const = 0;
    virtual void print() const = 0;
    virtual ~IPrintable() = default;
};

class Person : public IPrintable {
protected:
    string name;
    int age;

public:
    Person() : Person("Unknown", 16) {}
    Person(string c, int d) : name(c), age(d) {}
    Person(const Person& other) : name(other.name), age(other.age) {}
    Person(Person&& other) noexcept : name(move(other.name)), age(other.age) {}

    virtual void display() const {
        cout << "Client: " << name << ", Age: " << age << "\n" << "\n";
    }


    virtual ~Person() {
        // cout << "Person object destroyed.\n";
    }


    virtual void printInfo() const = 0;

    void print() const override {
        cout << "Printing Person: " << name << "\n" << "\n";
    }

};

class Customer : public Person {
private:
    string phoneNumber;
    int balance;

public:
    Customer() : Person(), phoneNumber("Unknown"), balance(0) {}
    Customer(string name, int age, string phone, int bal) : Person(name, age), phoneNumber(phone), balance(bal) {}

    void display() const override {
        cout << "Client: " << name << ", Age: " << age << ", Phone: " << phoneNumber << ", Balance: " << balance << "\n" << "\n";
    }

    void printInfo() const override {
        cout << "Customer Info: " << name << " - Balance: " << balance << "\n" << "\n";
    }


    void print() const override final {
        cout << "Printing Customer: " << name << "\n" << "\n";
    }


    ~Customer() {
        // cout << "Customer object destroyed.\n";
    }
};

class Race : public IPrintable {
private:
    string route;
    string timed;
    static int raceCount;

public:
    Race() : route("Unknown"), timed("00:00") { raceCount++; }
    Race(string a, string b) : route(a), timed(b) { raceCount++; }

    static int getRaceCount() { return raceCount; }

    void display() const override {
        cout << "Train: " << route << ", Arrival time: " << timed << "\n" << "\n";
    }

    void print() const override {
        cout << "Printing Race: " << route << "\n" << "\n";
    }

    void printInfo() const override {
        cout << "Race Info: " << route << ", Arrival time: " << timed << "\n" << "\n";
    }

    ~Race() {
        raceCount--;
        //cout << "Race object destroyed.\n";  
    }
};

int Race::raceCount = 0;

void PrintInfopPerson(Person& person) {

    person.display();
}

int main() {
    Customer customer1("Alex", 30, "123-456-789", 100);
    // customer1.display();

    // PrintInfopPerson(customer1);

    Person* personPtr = &customer1;
    // personPtr->display(); 
    // personPtr->printInfo();
    // personPtr->print();

    IPrintable* printablePtr = &customer1;
    // printablePtr->display(); 
    // printablePtr->printInfo();
    // printablePtr->print();

    Race race2("City-city", "20:30");
    // race2.display();

    printablePtr = &race2;
    // printablePtr->print();
    // printablePtr->display(); 
    // printablePtr->printInfo();

    cout << "Number of Race objects: " << Race::getRaceCount() << endl << endl;

    return 0;
}
