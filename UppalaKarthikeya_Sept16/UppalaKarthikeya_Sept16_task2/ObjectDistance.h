#ifndef OBJECT_DISTANCE_H
#define OBJECT_DISTANCE_H

#include <iostream>

class ObjectDistance
{
private:
    float radar_distance;
    float camera_distance;

public:
    // Constructor
    ObjectDistance(float radar, float camera);

    // Getters
    float getRadarDistance() const;
    float getCameraDistance() const;

    // Adjust functions
    void adjustDistancesByValue(ObjectDistance obj);
    void adjustDistancesByReference(ObjectDistance& obj);

    // Display
    void display() const;
};

// --- Global function declarations ---
void printObjectDistance(const ObjectDistance& obj);
ObjectDistance* createObjectDistanceOnHeap(float radar, float camera);

#endif // OBJECT_DISTANCE_H
