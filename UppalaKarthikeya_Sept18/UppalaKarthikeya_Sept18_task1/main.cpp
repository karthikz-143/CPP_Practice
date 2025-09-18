#include "VehicleStatus.h"
#include <iostream>

int main() {
    float wheelSpeed1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float engineTemp1[] = {90.5f, 88.9f};
    VehicleStatus vehicle1(4, wheelSpeed1, 2, engineTemp1);

    float wheelSpeed2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float engineTemp2[] = {92.0f, 89.5f};
    VehicleStatus vehicle2(4, wheelSpeed2, 2, engineTemp2);

    std::cout << " Vehicle 1 : \n"; 
    printVehicleStatus(vehicle1);

    std::cout << "\n Vehicle 2 : \n"; 
    printVehicleStatus(vehicle2);
    std::cout << (vehicle1.isWheelSpeedHigher(vehicle2) ? "Vehicle 1 wins\n" : "Vehicle 2 wins\n");

    std::cout << (compareWheelSpeedGlobal(vehicle1, vehicle2) ? "Vehicle 1 wins\n" : "Vehicle 2 wins\n");

    return 0;
}
