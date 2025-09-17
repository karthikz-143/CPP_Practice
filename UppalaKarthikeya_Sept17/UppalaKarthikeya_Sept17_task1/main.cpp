#include "Pedestrian.h"
#include <iostream>

int main() {
    const unsigned int size = 3;
    Pedestrian* arr = new Pedestrian[size] {
        Pedestrian(101, 12.4f),
        Pedestrian(102, 8.7f),
        Pedestrian(103, 15.1f)
    };

    std::cout << "\n--- All Pedestrians ---\n";
    for (unsigned int i = 0; i < size; i++) {
        arr[i].displayPedestrianInfo();
    }

    const Pedestrian* closest = nullptr;
    findClosestPedestrian(arr, size, closest);
    printClosestPedestrian(closest);

    std::cout << "\nUpdating Pedestrian 101 distance to 5.0...\n";
    arr[0].updateDistance(5.0f);
    arr[0].displayPedestrianInfo();

    std::cout << "\n--- After Update ---\n";
    findClosestPedestrian(arr, size, closest);
    printClosestPedestrian(closest);

    delete[] arr;
    return 0;
}
