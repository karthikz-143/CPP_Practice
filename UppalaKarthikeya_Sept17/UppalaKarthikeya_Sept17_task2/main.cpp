#include "TrackedVehicle.h"

int main() {
    const uint32_t size = 4;
    TrackedVehicle* arr = new TrackedVehicle[size] {
        {501, 80, 60},
        {502, 78, 45},
        {503, 85, 100},
        {504, 76, 40}
    };

    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(arr, size, lead);

    cout << "--- All Vehicles ---\n";
    for (uint32_t i = 0; i < size; ++i)
        printTrackedVehicle(arr[i]);

    cout << "\n--- Lead Vehicle ---\n";
    printLeadVehicle(lead);

    cout << "\nMin Recorded Distance: " << TrackedVehicle::getMinRecordedDistance() << " m\n";
    cout << "Total Vehicles Created: " << TrackedVehicle::getVehicleCount() << "\n";

    delete[] arr;
    return 0;
}
