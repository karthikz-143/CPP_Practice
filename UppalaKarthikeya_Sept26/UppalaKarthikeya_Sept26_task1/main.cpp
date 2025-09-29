#include "DoubleSubscriptedArray.h"
#include <iostream>

int main() {
    DoubleSubscriptedArray a(3, 5);  // 3x5 array

    std::cout << "Enter 15 integers for a 3x5 array:\n";
    std::cin >> a;

    std::cout << "\nArray a:\n" << a;

    a(1, 3) = 99;  // change element at row=1, col=3

    std::cout << "\nArray a after modifying element (1,3):\n" << a;

    DoubleSubscriptedArray b = a;  // copy constructor
    std::cout << "\nArray b (copy of a):\n" << b;

    std::cout << "\nComparing arrays: " 
              << (a == b ? "Equal" : "Not Equal") << std::endl;

    b(2, 4) = -7;
    std::cout << "\nArray b after modifying (2,4):\n" << b;
    std::cout << "Comparing arrays again: " 
              << (a != b ? "Not Equal" : "Equal") << std::endl;

    return 0;
}
