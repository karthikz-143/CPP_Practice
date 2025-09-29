#include <iostream>
#include "Polynomial.h"

int main() {
    Polynomial p1;
    p1.addTerm(3, 2); 
    p1.addTerm(4, 1); 
    p1.addTerm(2, 0); 

    Polynomial p2;
    p2.addTerm(5, 1);
    p2.addTerm(6, 0);

    std::cout << "P1 = " << p1 << std::endl;
    std::cout << "P2 = " << p2 << std::endl;

    std::cout << "P1 + P2 = " << (p1 + p2) << std::endl;
    std::cout << "P1 - P2 = " << (p1 - p2) << std::endl;
    std::cout << "P1 * P2 = " << (p1 * p2) << std::endl;

    p1 += p2;
    std::cout << "After P1 += P2: " << p1 << std::endl;

    p1 -= p2;
    std::cout << "After P1 -= P2: " << p1 << std::endl;

    p1 *= p2;
    std::cout << "After P1 *= P2: " << p1 << std::endl;

    return 0;
}
