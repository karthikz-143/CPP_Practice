#include <iostream>
#include "Date.h"

int main() {
    std::cout << "Case A: Incrementing into the next month\n";
    Date d1(1, 30, 2024); 
    for (int i = 0; i < 5; i++) {
        d1.printDate();
        d1.nextDay();
    }

    std::cout << "\nCase B: Incrementing into the next year\n";
    Date d2(12, 30, 2024); 
    for (int i = 0; i < 5; i++) {
        d2.printDate();
        d2.nextDay();
    }

    std::cout << "\nCase C: Leap year test (Feb 28 -> Feb 29)\n";
    Date d3(2, 27, 2024); 
    for (int i = 0; i < 5; i++) {
        d3.printDate();
        d3.nextDay();
    }

    return 0;
}
