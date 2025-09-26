#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial p1;
    p1.addTerm(3, 2); 
    p1.addTerm(4, 1);
    p1.addTerm(2, 0); 

    Polynomial p2;
    p2.addTerm(5, 1); 
    p2.addTerm(6, 0); 

    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    cout << "P1 + P2 = " << (p1 + p2) << endl;
    cout << "P1 - P2 = " << (p1 - p2) << endl;
    cout << "P1 * P2 = " << (p1 * p2) << endl;

    p1 += p2;
    cout << "After P1 += P2: " << p1 << endl;

    p1 -= p2;
    cout << "After P1 -= P2: " << p1 << endl;

    p1 *= p2;
    cout << "After P1 *= P2: " << p1 << endl;

    return 0;
}
