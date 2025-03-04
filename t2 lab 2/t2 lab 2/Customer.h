#ifndef CUSTOMER_H  
#define CUSTOMER_H  

#include <string>  
using namespace std;

class Customer {
private:
    string name;  
    int age;     
public:
    Customer();  
    Customer(string c, int d); 
    void display();  
    ~Customer();  
};

#endif 