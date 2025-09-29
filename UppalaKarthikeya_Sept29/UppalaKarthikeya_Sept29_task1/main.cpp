#include "ArrayOperations.h"

int main()
{
    ArrayOperations operations;

    // Declare a pointer to double
    double* numberPointer = nullptr;

    // Assign starting address of array to pointer in two ways
    numberPointer = (double*)&operations; 
    // Not valid direct -> better inside class
    // Instead, correctly assign using array reference
    numberPointer = reinterpret_cast<double*>(&operations); // assign array base address
    numberPointer = (double*)((void*)&operations);          // second assignment form

    // demonstration calls
    operations.printWithArraySubscript();
    operations.printWithPointerOffset(numberPointer);
    operations.printWithArrayNameAsPointer();
    operations.printWithPointerSubscript(numberPointer);

    operations.demonstrateElementReferences(numberPointer);
    operations.demonstratePointerArithmetic(numberPointer);

    return 0;
}
