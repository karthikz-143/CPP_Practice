#include "UppalaKarthikeya_Oct1_Task1_HybridVehicle.h"

int main()
{
    // Create two HybridVehicle objects
    HybridVehicle v1("Prius", 120.5F, 80.0F, 4.5F);
    HybridVehicle v2("Volt", 100.0F, 90.0F, 5.0F);

    // Assign trips
    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    //Display vehicles
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    // Combine using +
    HybridVehicle combined = v1 + v2;
    std::cout << "Combined Vehicle: " << combined << std::endl;

    // Compare efficiency using ==
    if (v1 == v2)
    {
        std::cout << "Vehicles have equal efficiency." << std::endl;
    }
    else
    {
        std::cout << "Vehicles have different efficiency." << std::endl;
    }

    ++v1;
    std::cout << "After increment, v1: " << v1 << std::endl;

    // Access a trip using []
    std::cout << "v1 first trip distance: " << v1[0] << " km" << std::endl;

    //  Use () to get total distance
    std::cout << "Total distance of v1: " << v1() << " km" << std::endl;

    // Use float() to get efficiency
    std::cout << "Efficiency of v2: " << static_cast<float>(v2) << " km/L" << std::endl;

    // Test assignment operator for deep copy
    HybridVehicle v3;
    v3 = v1;  // deep copy
    std::cout << "Copied v3 from v1: " << v3 << std::endl;

    return 0;
}
