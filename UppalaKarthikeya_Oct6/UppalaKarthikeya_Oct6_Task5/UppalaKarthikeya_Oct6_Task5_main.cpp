#include "UppalaKarthikeya_Oct6_Task5_Package.h"
#include <iostream>

int main() {
    Package basePkg("Alice", "123 Main St", "Boston", "MA", "02118",
                    "Bob", "456 Oak St", "Chicago", "IL", "60616",
                    10, 0.5);

    TwoDayPackage twoDayPkg("Charlie", "12 Hill Rd", "Dallas", "TX", "75001",
                            "Diana", "98 Lake View", "Seattle", "WA", "98101",
                            10, 0.5, 2.0);

    OvernightPackage overnightPkg("Eve", "77 Park Ave", "Miami", "FL", "33101",
                                  "Frank", "44 Pine St", "Denver", "CO", "80202",
                                  10, 0.5, 0.25);

    std::cout << "\n Base Package:\n";
    basePkg.printInfo();
    std::cout << "Cost: $" << basePkg.calculateCost() << std::endl;

    std::cout << "\n TwoDay Package:\n";
    twoDayPkg.printInfo();
    std::cout << "Cost: $" << twoDayPkg.calculateCost() << std::endl;

    std::cout << "\n Overnight Package:\n";
    overnightPkg.printInfo();
    std::cout << "Cost: $" << overnightPkg.calculateCost() << std::endl;

    return 0;
}
