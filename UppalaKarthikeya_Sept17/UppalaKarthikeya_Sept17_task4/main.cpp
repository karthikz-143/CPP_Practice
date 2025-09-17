#include "SensorArray.h"

int main() {
    double lidarReadings[] = {35.5, 36.1, 34.9};
    double radarReadings[] = {39.0, 38.7, 39.3};
    double cameraReadings[] = {30.2, 31.0, 30.5};

    SensorArray* sensors = new SensorArray[3]{
        SensorArray(801, LIDAR, lidarReadings, 3),
        SensorArray(802, RADAR, radarReadings, 3),
        SensorArray(803, CAMERA, cameraReadings, 3)
    };

    printAllSensors(sensors, 3);

    std::cout << "Global Max Temperature: "
              << SensorArray::getGlobalMaxTemperature() << "\n";

    delete[] sensors;
    return 0;
}
