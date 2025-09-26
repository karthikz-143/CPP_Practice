#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main() {
    RationalNumber r1(3, 4);   // 3/4
    RationalNumber r2(5, 6);   // 5/6

    cout << "R1 = " << r1 << endl;
    cout << "R2 = " << r2 << endl;

    cout << "Addition: " << (r1 + r2) << endl;
    cout << "Subtraction: " << (r1 - r2) << endl;
    cout << "Multiplication: " << (r1 * r2) << endl;
    cout << "Division: " << (r1 / r2) << endl;

    cout << "R1 == R2 ? " << (r1 == r2 ? "Yes" : "No") << endl;
    cout << "R1 < R2 ? " << (r1 < r2 ? "Yes" : "No") << endl;
    cout << "R1 > R2 ? " << (r1 > r2 ? "Yes" : "No") << endl;

    return 0;
}
