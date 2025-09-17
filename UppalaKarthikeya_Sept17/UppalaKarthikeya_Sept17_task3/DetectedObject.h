#ifndef DETECTEDOBJECT_H
#define DETECTEDOBJECT_H

#include <cstdint>

class DetectedObject {
private:
    uint32_t object_id;
    float rel_speed;
    float distance;

public:
    DetectedObject(uint32_t id, float speed, float dist)
        : object_id(id), rel_speed(speed), distance(dist) {}

    void updateValuesByValue(DetectedObject obj);
    void updateValuesByReference(DetectedObject& obj);

    uint32_t getId() const { return object_id; }
    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
};

void updateObjectValuesByValueGlobal(DetectedObject obj);
void updateObjectValuesByReferenceGlobal(DetectedObject& obj);

#endif
