#include "Values.h"

void printArraySubscript(const unsigned int values[]) {
    std::cout << "Array elements using subscript notation: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

void printPointerOffset(const unsigned int* vPtr) {
    std::cout << "Array elements using pointer/offset notation: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(vPtr + i) << " ";
    }
    std::cout << std::endl;
}
void printArrayNameAsPointer(const unsigned int values[]) {
    std::cout << "Array elements using array name as pointer: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(values + i) << " ";
    }
    std::cout << std::endl;
}

void printPointerSubscript(const unsigned int* vPtr) {
    std::cout << "Array elements using pointer subscript notation: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << vPtr[i] << " ";
    }
    std::cout << std::endl;
}

// h) Demonstrate accessing the 5th element using different notations
void demonstrateElementAccess(const unsigned int values[], const unsigned int* vPtr) {
    std::cout << "Accessing 5th element of array in multiple ways:" << std::endl;
    std::cout << "values[4] = " << values[4] << std::endl;
    std::cout << "*(values + 4) = " << *(values + 4) << std::endl;
    std::cout << "vPtr[4] = " << vPtr[4] << std::endl;
    std::cout << "*(vPtr + 4) = " << *(vPtr + 4) << std::endl;
}

void demonstrateAddressing(const unsigned int values[], unsigned int* vPtr) {
    std::cout << "\n--- Addressing Demonstration ---" << std::endl;

    std::cout << "Address referenced by vPtr + 3: " << (vPtr + 3) << std::endl;
    std::cout << "Value at that address: " << *(vPtr + 3) << std::endl;

    vPtr = (unsigned int*)&values[4];
    vPtr -= 4; // move back to start of array
    std::cout << "After vPtr -= 4, address referenced: " << vPtr << std::endl;
    std::cout << "Value stored at that address: " << *vPtr << std::endl;
}
