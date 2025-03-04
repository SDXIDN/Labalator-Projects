#include <iostream>  
#include "Race.h"  

using namespace std;

Race::Race() : route("Unknown"), time(0) {}

Race::Race(string a, string b) : route(a), time(b) {}

void Race::display() {
    cout << "Потяг: " << route << ", Час прибуття: " << time << "\n";
}

Race::~Race() {
    cout << "Race об'єкт знищено.\n";
}