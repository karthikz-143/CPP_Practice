#include "UppalaKarthikeya_Oct6_Task1_CommissionEmployee.h"
#include <iostream>

int main() {
    BasePlusCommissionEmployee employee("Karthikeya", "Uppala", "123-45-6789",
                                        5000, 0.06, 300);

    std::cout << employee.toString()
              << "\nEarnings: " << employee.earnings()
              << std::endl;

    return 0;
}
