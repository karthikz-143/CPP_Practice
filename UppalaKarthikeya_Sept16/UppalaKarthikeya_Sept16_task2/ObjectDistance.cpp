#include "ObjectDistance.h"
#include <iomanip>

// Constructor
ObjectDistance::ObjectDistance(float radar, float camera)
    : radar_distance(radar), camera_distance(camera) {}

// Getters
float ObjectDistance::getRadarDistance() const { return radar_distance; }
float ObjectDistance::getCameraDistance() const { return camera_distance; }

// Pass by Value
void ObjectDistance::adjustDistancesByValue(ObjectDistance obj) {
    obj.radar_distance += 5.0f;
    obj.camera_distance += 5.0f;
    std::cout << "(adjustDistancesByValue) Copy modified: "
              << obj.radar_distance << ", " << obj.camera_distance << std::endl;
}

// Pass by Reference
void ObjectDistance::adjustDistancesByReference(ObjectDistance& obj) {
    obj.radar_distance += 5.0f;
    obj.camera_distance += 5.0f;
    std::cout << "(adjustDistancesByReference) Object modified: "
              << obj.radar_distance << ", " << obj.camera_distance << std::endl;
}

// Display
void ObjectDistance::display() const {
    std::cout << "Radar: " << radar_distance
              << ", Camera: " << camera_distance << std::endl;
}

// Global: printObjectDistance
void printObjectDistance(const ObjectDistance& obj) {
    std::cout << "Radar: " << obj.getRadarDistance()
              << ", Camera: " << obj.getCameraDistance() << std::endl;
}

// Global: createObjectDistanceOnHeap
ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}
