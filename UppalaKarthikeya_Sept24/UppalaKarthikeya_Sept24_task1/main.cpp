#include <iostream>
#include "Time.h"

int main() {
    std::cout << "Case A: Incrementing into the next minute\n";
    Time t1(10, 59, 58);
    for (int i = 0; i < 5; i++) {
        t1.printStandard();
        t1.tick();
    }

    std::cout << "\nCase B: Incrementing into the next hour\n";
    Time t2(1, 59, 58);
    for (int i = 0; i < 5; i++) {
        t2.printStandard();
        t2.tick();
    }

    std::cout << "\nCase C: Incrementing into the next day\n";
    Time t3(23, 59, 58); // 11:59:58 PM
    for (int i = 0; i < 5; i++) {
        t3.printStandard();
        t3.tick();
    }

    return 0;
}
