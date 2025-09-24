#include <iostream>
#include "Time.h"

int main() {
    Time t; 

    std::cout << "Initial universal time: ";
    t.printUniversal();
    std::cout << "\nInitial standard time: ";
    t.printStandard();
    std::cout << "\n\n";

 
    if (!t.setTime(13, 27, 6)) {
        std::cout << "Error: invalid time (13, 27, 6)\n";
    }

    std::cout << "After setting valid time:\n";
    t.printUniversal();
    std::cout << " (Universal)\n";
    t.printStandard();
    std::cout << " (Standard)\n\n";

    
    if (!t.setHour(99)) {
        std::cout << "Error: invalid hour (99)\n";
    }

   
    if (!t.setMinute(70)) {
        std::cout << "Error: invalid minute (70)\n";
    }

    
    if (!t.setSecond(-5)) {
        std::cout << "Error: invalid second (-5)\n";
    }

    std::cout << "\nFinal time after invalid attempts:\n";
    t.printUniversal();
    std::cout << " (Universal)\n";
    t.printStandard();
    std::cout << " (Standard)\n";

    return 0;
}
