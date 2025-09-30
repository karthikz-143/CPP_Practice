#ifndef VALUES_H
#define VALUES_H

#include <iostream>

// Define the size of the array
const int SIZE = 5;

// Function declarations
void printArraySubscript(const unsigned int values[]);
void printPointerOffset(const unsigned int* vPtr);
void printArrayNameAsPointer(const unsigned int values[]);
void printPointerSubscript(const unsigned int* vPtr);
void demonstrateElementAccess(const unsigned int values[], const unsigned int* vPtr);
void demonstrateAddressing(const unsigned int values[], unsigned int* vPtr);

#endif
