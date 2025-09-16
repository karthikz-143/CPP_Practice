#include "ObjectDistance.h"
#include <iostream>

int main()
{
    std::cout << "--- Sensor Fusion (ADAS) ---" << std::endl;

    // Create object on heap
    ObjectDistance* obj = createObjectDistanceOnHeap(35.5f, 34.8f);

    std::cout << "\nInitial distances:" << std::endl;
    printObjectDistance(*obj);

    // Pass by Value
    std::cout << "\n--- adjustDistancesByValue ---" << std::endl;
    obj->adjustDistancesByValue(*obj);
    printObjectDistance(*obj);

    // Pass by Reference
    std::cout << "\n--- adjustDistancesByReference ---" << std::endl;
    obj->adjustDistancesByReference(*obj);
    printObjectDistance(*obj);

    // Delete heap object
    delete obj;
    obj = nullptr;

    std::cout << "\nObject deleted. Program finished." << std::endl;
    return 0;
}
