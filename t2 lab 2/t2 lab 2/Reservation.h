#ifndef RESERVATION_H  
#define RESERVATION_H  

#include <string>  
#include "Race.h"  
#include "Customer.h"  
using namespace std;


class Reservation {
private:
    Customer customer;  
    Race race;         
    string bookingDate; 
public:
    Reservation();  
    Reservation(Customer c, Race r, string date);
    void display();  
    ~Reservation(); 
};

#endif 