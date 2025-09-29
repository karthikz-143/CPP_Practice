#include <iostream>
#include "HugeInt.h"

int main() {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    std::cout << "n1 = " << n1 << "\nn2 = " << n2
              << "\nn3 = " << n3 << "\nn4 = " << n4
              << "\nn5 = " << n5 << "\n\n";

    n5 = n1 + n2;
    std::cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    n5 = n1 * n2;
    std::cout << n1 << " * " << n2 << " = " << n5 << "\n\n";

    std::cout << n3 << " + " << n4 << " = " << (n3 + n4) << "\n\n";

    std::cout << "Comparisons:\n";
    std::cout << n1 << " == " << n2 << " ? " << (n1 == n2) << std::endl;
    std::cout << n1 << " != " << n2 << " ? " << (n1 != n2) << std::endl;
    std::cout << n1 << " < " << n2  << " ? " << (n1 < n2) << std::endl;
    std::cout << n1 << " > " << n2  << " ? " << (n1 > n2) << std::endl;

    return 0;
}
