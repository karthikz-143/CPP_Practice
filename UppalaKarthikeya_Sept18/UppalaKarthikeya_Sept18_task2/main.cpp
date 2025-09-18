#include "EgoVehicleData.h"
#include <iostream>

int main() {
    float lanes1[] = {3.2f, 3.0f, 3.4f};
    float conf1[] = {0.95f, 0.97f, 0.93f};
    float lanes2[] = {2.9f, 2.8f, 3.1f};
    float conf2[] = {0.92f, 0.90f, 0.88f};
    float lanes3[] = {3.4f, 3.5f, 3.6f};
    float conf3[] = {0.99f, 0.98f, 0.97f};
    EgoVehicleData* vehicles = new EgoVehicleData[3]{
        EgoVehicleData(3, lanes1, conf1),
        EgoVehicleData(3, lanes2, conf2),
        EgoVehicleData(3, lanes3, conf3)
    };
    for (int i = 0; i < 3; ++i) {
        vehicles[i].updateSensorConfidence(1.05f + i * 0.05f);
        printEgoVehicleData(vehicles[i]);
    }
    const EgoVehicleData* best = nullptr;
    findHighestConfidenceVehicle(vehicles, 3, best);
    printHighestConfidenceVehicle(best);
    delete[] vehicles;
    return 0;
}
