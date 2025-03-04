#include <iostream>  
#include "Customer.h"  

using namespace std;

  
Customer::Customer() : Customer("Unknown", 16) {}

 
Customer::Customer(string c, int d) : name(c), age(d) {}

 
void Customer::display() {
    cout << "Клієнт: " << name << ", Вік: " << age << "\n";
}

 
Customer::~Customer() {
    cout << "Customer об'єкт знищено.\n";
}