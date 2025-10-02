#include <iostream>
#include "UppalaKarthikeya_Oct2_Task2_BatteryMonitor.h"

int main()
{
    BatteryMonitor s1("SCT101", 300, 4.0F, 5.0F, true, 3);
    BatteryMonitor s2("SCT202", 150, 3.5F, 5.0F, true, 2);

    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    if (s1 > s2) std::cout << "s1 has better battery health." << std::endl;
    else if (s1 < s2) std::cout << "s2 has better battery health." << std::endl;
    else std::cout << "Both scooters have equal health." << std::endl;

    s1 += 50;
    std::cout << "After 50 charge cycles, s1: " << s1 << std::endl;

    if (!s2) std::cout << "s2 is inactive." << std::endl;
    else std::cout << "s2 is active." << std::endl;

    BatteryMonitor s3 = s1;  // deep copy
    std::cout << "s3 copied from s1: " << s3 << std::endl;

    return 0;
}
