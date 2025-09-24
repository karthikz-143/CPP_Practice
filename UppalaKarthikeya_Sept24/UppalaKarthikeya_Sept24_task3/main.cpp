#include <iostream>
#include "DateAndTime.h"

int main() {
    std::cout << "Case A: Incrementing into the next minute\n";
    DateAndTime dt1(5, 15, 2024, 10, 59, 58); 
    for (int i = 0; i < 5; i++) {
        dt1.printStandard();
        dt1.tick();
    }

    std::cout << "\nCase B: Incrementing into the next hour\n";
    DateAndTime dt2(5, 15, 2024, 1, 59, 58);
    for (int i = 0; i < 5; i++) {
        dt2.printUniversal();
        dt2.tick();
    }

    std::cout << "\nCase C: Incrementing into the next day\n";
    DateAndTime dt3(12, 31, 2024, 23, 59, 58); 
    for (int i = 0; i < 5; i++) {
        dt3.printStandard();
        dt3.tick();
    }

    return 0;
}
