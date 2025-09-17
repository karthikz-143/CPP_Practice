#include "DetectedObject.h"
#include <iostream>

void DetectedObject::updateValuesByValue(DetectedObject obj) {
    this->object_id = obj.object_id;
    this->rel_speed = obj.rel_speed;
    this->distance = obj.distance;
}

void DetectedObject::updateValuesByReference(DetectedObject& obj) {
    this->object_id = obj.object_id;
    this->rel_speed = obj.rel_speed;
    this->distance = obj.distance;
}

void updateObjectValuesByValueGlobal(DetectedObject obj) {
    obj.updateValuesByValue(obj);
    std::cout << "Global by Value: updated copy (no effect on original)\n";
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj) {
    obj.updateValuesByReference(obj);
    std::cout << "Global by Reference: original object updated\n";
}
