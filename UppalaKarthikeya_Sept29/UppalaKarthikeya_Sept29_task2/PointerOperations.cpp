#include "PointerOperations.h"

// Constructor initializes number1, number2, ptr, s1, s2
PointerOperations::PointerOperations()
{
    number1 = 7.3;
    number2 = 0.0;
    fPtr = nullptr;
    ptr = nullptr;

    // Initialize strings
    std::strcpy(s1, "HelloStringOne");
    std::strcpy(s2, "HelloStringTwo");
}

// (b) Assign address of number1 to pointer variable fPtr
void PointerOperations::assignPointer()
{
    fPtr = &number1;
}

// (c) Print value of the object pointed to by fPtr
void PointerOperations::printPointedValue() const
{
    std::cout << "Value pointed to by fPtr: " << *fPtr << "\n";
}

// (d) Assign the value of the object pointed to by fPtr to variable number2
void PointerOperations::assignToNumber2()
{
    number2 = *fPtr;
}

// (e) Print value of number2
void PointerOperations::printNumber2() const
{
    std::cout << "Value of number2: " << number2 << "\n";
}

// (f) Print address of number1
void PointerOperations::printAddressOfNumber1() const
{
    std::cout << "Address of number1: " << &number1 << "\n";
}

// (g) Print address stored in fPtr
void PointerOperations::printAddressInPointer() const
{
    std::cout << "Address stored in fPtr: " << fPtr << "\n";
    std::cout << "Is this same as &number1? Yes.\n";
}
