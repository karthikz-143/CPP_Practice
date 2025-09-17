#ifndef TRACKEDVEHICLE_H
#define TRACKEDVEHICLE_H

#include <iostream>
#include <cstdint>
using namespace std;

class TrackedVehicle {
    uint32_t vehicle_id;
    float speed;
    float distance;

    static float min_recorded_distance;
    static int vehicle_count;

public:
    TrackedVehicle(uint32_t id, float spd, float dist);
    void display() const;
    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const;

    static float getMinRecordedDistance() { return min_recorded_distance; }
    static int getVehicleCount() { return vehicle_count; }
};

// Global functions
void printTrackedVehicle(const TrackedVehicle& vehicle);
void printLeadVehicle(const TrackedVehicle* lead);
void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead);

#endif
