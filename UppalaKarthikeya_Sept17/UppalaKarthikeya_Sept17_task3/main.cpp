#include <iostream>
#include "DetectedObject.h"

int main() {
    DetectedObject obj1(1, 50.0f, 100.0f);
    DetectedObject obj2(2, 70.0f, 200.0f);

    std::cout << "Before update:\n";
    std::cout << "Obj1 -> ID: " << obj1.getId()
              << ", Speed: " << obj1.getRelSpeed()
              << ", Distance: " << obj1.getDistance() << "\n";
    std::cout << "Obj2 -> ID: " << obj2.getId()
              << ", Speed: " << obj2.getRelSpeed()
              << ", Distance: " << obj2.getDistance() << "\n";

    obj1.updateValuesByValue(obj2);
    std::cout << "\nAfter updateValuesByValue (obj1 from obj2):\n";
    std::cout << "Obj1 -> ID: " << obj1.getId()
              << ", Speed: " << obj1.getRelSpeed()
              << ", Distance: " << obj1.getDistance() << "\n";

    obj2.updateValuesByReference(obj1);
    std::cout << "\nAfter updateValuesByReference (obj2 from obj1):\n";
    std::cout << "Obj2 -> ID: " << obj2.getId()
              << ", Speed: " << obj2.getRelSpeed()
              << ", Distance: " << obj2.getDistance() << "\n";

    std::cout << "\n--- Global Functions ---\n";
    updateObjectValuesByValueGlobal(obj1);
    updateObjectValuesByReferenceGlobal(obj2);

    std::cout << "Obj1 -> ID: " << obj1.getId()
              << ", Speed: " << obj1.getRelSpeed()
              << ", Distance: " << obj1.getDistance() << "\n";
    std::cout << "Obj2 -> ID: " << obj2.getId()
              << ", Speed: " << obj2.getRelSpeed()
              << ", Distance: " << obj2.getDistance() << "\n";

    return 0;
}
