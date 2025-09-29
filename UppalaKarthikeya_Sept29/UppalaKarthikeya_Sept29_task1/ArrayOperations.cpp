#include "ArrayOperations.h"

// Constructor 
ArrayOperations::ArrayOperations()
{
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = i * 1.1;
    }
}

// Display elements using array subscript notation
void ArrayOperations::printWithArraySubscript() const
{
    std::cout << "Array elements (Array Subscript Notation):\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::fixed << std::setprecision(1) << numbers[i] << " ";
    }
    std::cout << "\n";
}

// Displays elements using pointer/offset notation with pointer
void ArrayOperations::printWithPointerOffset(double* pointer) const
{
    std::cout << "Array elements (Pointer/Offset with pointer):\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::fixed << std::setprecision(1) << *(pointer + i) << " ";
    }
    std::cout << "\n";
}
// Displays elements using pointer/offset notation with array name
void ArrayOperations::printWithArrayNameAsPointer() const
{
    std::cout << "Array elements (Pointer/Offset with array name):\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::fixed << std::setprecision(1) << *(numbers + i) << " ";
    }
    std::cout << "\n";
}

// Displays elements using pointer subscript notation with pointer
void ArrayOperations::printWithPointerSubscript(double* pointer) const
{
    std::cout << "Array elements (Pointer/Subscript Notation):\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::fixed << std::setprecision(1) << pointer[i] << " ";
    }
    std::cout << "\n";
}

// Demonstrates accessing the 4th element in multiple ways
void ArrayOperations::demonstrateElementReferences(double* pointer) const
{
    std::cout << "Fourth element access in different ways:\n";
    std::cout << "Array subscript: " << numbers[3] << "\n";
    std::cout << "Pointer/Offset with array name: " << *(numbers + 3) << "\n";
    std::cout << "Pointer subscript with nPtr: " << pointer[3] << "\n";
    std::cout << "Pointer/Offset with nPtr: " << *(pointer + 3) << "\n";
}

// Demonstrates pointer arithmetic questions (i and j)
void ArrayOperations::demonstratePointerArithmetic(double* pointer) const
{
    std::cout << "Pointer arithmetic demonstration:\n";


    double* caseI = pointer + 8;
    std::cout << "Address referenced by nPtr + 8: " << caseI << "\n";
    std::cout << "Value at nPtr + 8: " << *caseI << "\n";

    
    double* caseJ = pointer + 5; 
    caseJ -= 4;
    std::cout << "Address referenced after nPtr -= 4: " << caseJ << "\n";
    std::cout << "Value at that address: " << *caseJ << "\n";
}
