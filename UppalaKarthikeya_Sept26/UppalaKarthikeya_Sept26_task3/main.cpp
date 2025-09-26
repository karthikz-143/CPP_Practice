// main.cpp
#include <iostream>
#include "HugeInt.h"
using namespace std;

int main() {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    cout << "n1 = " << n1 << "\nn2 = " << n2
         << "\nn3 = " << n3 << "\nn4 = " << n4
         << "\nn5 = " << n5 << "\n\n";

    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    n5 = n1 * n2;
    cout << n1 << " * " << n2 << " = " << n5 << "\n\n";

    cout << n3 << " + " << n4 << " = " << (n3 + n4) << "\n\n";

    cout << "Comparisons:\n";
    cout << n1 << " == " << n2 << " ? " << (n1 == n2) << endl;
    cout << n1 << " != " << n2 << " ? " << (n1 != n2) << endl;
    cout << n1 << " < " << n2  << " ? " << (n1 < n2) << endl;
    cout << n1 << " > " << n2  << " ? " << (n1 > n2) << endl;
}
