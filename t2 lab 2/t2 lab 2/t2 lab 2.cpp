#include <iostream>  
#include "Race.h"  
#include "Customer.h"  
#include "Reservation.h"  
#include "windows.h" 
using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    
    Race race1("cityy", "20:30");
    race1.display();  

    
    Customer customer1("Іван", 23);
    customer1.display();  

    
    Reservation reservation1(customer1, race1, "2023-10-30");
    reservation1.display();  

    return 0;
}