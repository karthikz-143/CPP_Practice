#ifndef POINTER_OPERATIONS_H
#define POINTER_OPERATIONS_H

#include <iostream>
#include <iomanip>
#include <cstring>

class PointerOperations
{
private:
    double number1;
    double number2;
    double* fPtr;     // Pointer to double
    char* ptr;        // Pointer to char
    char s1[100];
    char s2[100];

public:
    PointerOperations();

    void assignPointer();
    void printPointedValue() const;
    void assignToNumber2();
    void printNumber2() const;
    void printAddressOfNumber1() const;
    void printAddressInPointer() const;
};

#endif
