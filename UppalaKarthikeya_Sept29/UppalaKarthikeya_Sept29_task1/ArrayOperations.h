#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <iostream>
#include <iomanip>

const int SIZE = 10;

class ArrayOperations
{
private:
    // Array of double numbers
    double numbers[SIZE];

public:
    // Constructor
    ArrayOperations();
    // Member functions
    void printWithArraySubscript() const;
    void printWithPointerOffset(double* pointer) const;
    void printWithArrayNameAsPointer() const;
    void printWithPointerSubscript(double* pointer) const;
    void demonstrateElementReferences(double* pointer) const;
    void demonstratePointerArithmetic(double* pointer) const;
};

#endif
