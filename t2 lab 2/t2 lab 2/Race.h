#ifndef RACE_H  
#define RACE_H  

#include <string>  
using namespace std;

class Race {
private:
    string route;
    string time;
public:
    Race();
    Race(string a, string b);
    void display();
    ~Race();
};

#endif 