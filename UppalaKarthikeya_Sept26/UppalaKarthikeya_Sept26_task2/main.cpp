#include <iostream>
#include "Complex.h"

int main() {
    Complex x;                  // default (0, 0)
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    std::cout << "z: " << z << '\n';

    x = y + z;
    std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';

    x = y - z;
    std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';

    Complex m = y * z;
    std::cout << "\ny * z = " << m << '\n';

    std::cout << "y == z ? " << (y == z ? "true" : "false") << '\n';
    std::cout << "y != z ? " << (y != z ? "true" : "false") << '\n';

    Complex user;
    std::cout << "\nEnter a complex number in the form (a, b): ";
    if (std::cin >> user) {
        std::cout << "You entered: " << user << '\n';
    } else {
        std::cout << "Invalid input format.\n";
    }

    return 0;
}
