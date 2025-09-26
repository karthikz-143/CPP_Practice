#include "DoubleSubscriptedArray.h"

int main() {
    DoubleSubscriptedArray a(3, 5);  // 3x5 array

    cout << "Enter 15 integers for a 3x5 array:\n";
    cin >> a;

    cout << "\nArray a:\n" << a;

    a(1, 3) = 99;  // change element at row=1, col=3

    cout << "\nArray a after modifying element (1,3):\n" << a;

    DoubleSubscriptedArray b = a;  // copy constructor
    cout << "\nArray b (copy of a):\n" << b;

    cout << "\nComparing arrays: " 
         << (a == b ? "Equal" : "Not Equal") << endl;

    b(2, 4) = -7;
    cout << "\nArray b after modifying (2,4):\n" << b;
    cout << "Comparing arrays again: " 
         << (a != b ? "Not Equal" : "Equal") << endl;

    return 0;
}
