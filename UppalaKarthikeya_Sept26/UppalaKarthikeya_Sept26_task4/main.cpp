#include <iostream>
#include "RationalNumber.h"

int main() {
    RationalNumber r1(3, 4);   // 3/4
    RationalNumber r2(5, 6);   // 5/6

    std::cout << "R1 = " << r1 << std::endl;
    std::cout << "R2 = " << r2 << std::endl;

    std::cout << "Addition: " << (r1 + r2) << std::endl;
    std::cout << "Subtraction: " << (r1 - r2) << std::endl;
    std::cout << "Multiplication: " << (r1 * r2) << std::endl;
    std::cout << "Division: " << (r1 / r2) << std::endl;

    std::cout << "R1 == R2 ? " << (r1 == r2 ? "Yes" : "No") << std::endl;
    std::cout << "R1 != R2 ? " << (r1 != r2 ? "Yes" : "No") << std::endl;
    std::cout << "R1 < R2 ? " << (r1 < r2 ? "Yes" : "No") << std::endl;
    std::cout << "R1 > R2 ? " << (r1 > r2 ? "Yes" : "No") << std::endl;
    std::cout << "R1 <= R2 ? " << (r1 <= r2 ? "Yes" : "No") << std::endl;
    std::cout << "R1 >= R2 ? " << (r1 >= r2 ? "Yes" : "No") << std::endl;


    return 0;
}
