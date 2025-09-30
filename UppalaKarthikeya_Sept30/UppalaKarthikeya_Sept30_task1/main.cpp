#include "Values.h"

int main() {
    // a) Declare and initialize array
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // b) Declare pointer vPtr
    unsigned int* vPtr = nullptr;

    // d) Assign starting address of array values to vPtr
    vPtr = values;        
    vPtr = &values[0];     

    printArraySubscript(values);       // (c)
    printPointerOffset(vPtr);          // (e)
    printArrayNameAsPointer(values);   // (f)
    printPointerSubscript(vPtr);       // (g)
    demonstrateElementAccess(values, vPtr);  // (h)
    demonstrateAddressing(values, vPtr);     // (i, j)

    return 0;
}
