#include "TrackedVehicle.h"

// Initialize static members
float TrackedVehicle::min_recorded_distance = 1e9;
int TrackedVehicle::vehicle_count = 0;

TrackedVehicle::TrackedVehicle(uint32_t id, float spd, float dist) 
    : vehicle_id(id), speed(spd), distance(dist) {
    if (dist < min_recorded_distance) min_recorded_distance = dist;
    vehicle_count++;
}

void TrackedVehicle::display() const {
    cout << "ID: " << vehicle_id 
         << ", Speed: " << speed 
         << " km/h, Distance: " << distance << " m\n";
}

const TrackedVehicle* TrackedVehicle::compareDistance(const TrackedVehicle& other) const {
    if (this->distance <= other.distance) return this;
    return &other;
}

// Global functions
void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
}

void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead) lead->display();
    else cout << "Lead Vehicle: None found\n";
}

void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead) {
    lead = &arr[0];
    for (uint32_t i = 1; i < size; ++i)
        lead = lead->compareDistance(arr[i]);
}
