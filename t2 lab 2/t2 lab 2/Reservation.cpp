#include <iostream>  
#include "Reservation.h"  

using namespace std;

  
Reservation::Reservation() : customer(), race(), bookingDate("Unknown") {}

Reservation::Reservation(Customer c, Race r, string date) : customer(c), race(r), bookingDate(date) {}


void Reservation::display() {
    cout << "Бронювання: \n";
    customer.display();      
    race.display();         
    cout << "Дата бронювання: " << bookingDate << "\n"; 
}

Reservation::~Reservation() {
    cout << "Reservation об'єкт знищено.\n";
}