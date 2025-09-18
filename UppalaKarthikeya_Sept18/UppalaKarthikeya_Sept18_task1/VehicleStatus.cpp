#include "VehicleStatus.h"
#include <iostream>

VehicleStatus::VehicleStatus(int numWheels, const float* wheelSpeedData, int numTemps, const float* engineTempData)
    : num_wheels(numWheels), num_temps(numTemps) {
    wheel_speed = new float[num_wheels];
    for (int i = 0; i < num_wheels; ++i) wheel_speed[i] = wheelSpeedData[i];

    engine_temp = new float[num_temps];
    for (int i = 0; i < num_temps; ++i) engine_temp[i] = engineTempData[i];
}

VehicleStatus::~VehicleStatus() {
    delete[] wheel_speed;
    delete[] engine_temp;
}

float VehicleStatus::averageWheelSpeed() const {
    if (num_wheels == 0) return 0.0f;
    float sum = 0;
    for (int i = 0; i < num_wheels; ++i) sum += wheel_speed[i];
    return sum / num_wheels;
}

float VehicleStatus::maxEngineTemp() const {
    if (num_temps == 0) return 0.0f;
    float maxTemp = engine_temp[0];
    for (int i = 1; i < num_temps; ++i)
        if (engine_temp[i] > maxTemp) maxTemp = engine_temp[i];
    return maxTemp;
}

float VehicleStatus::findMaxWheelSpeed() const {
    if (num_wheels == 0) return 0.0f;
    float maxSpeed = wheel_speed[0];
    for (int i = 1; i < num_wheels; ++i)
        if (wheel_speed[i] > maxSpeed) maxSpeed = wheel_speed[i];
    return maxSpeed;
}

bool VehicleStatus::isWheelSpeedHigher(const VehicleStatus& other) const {
    return findMaxWheelSpeed() > other.findMaxWheelSpeed();
}

void printVehicleStatus(const VehicleStatus& vs) {
    std::cout << "Wheel Speeds: [";
    for (int i = 0; i < vs.getNumWheels(); ++i)
        std::cout << vs.getWheelSpeed()[i] << (i == vs.getNumWheels() - 1 ? "" : ", ");
    std::cout << "]\n";

    std::cout << "Engine Temps: [";
    for (int i = 0; i < vs.getNumTemps(); ++i)
        std::cout << vs.getEngineTemp()[i] << (i == vs.getNumTemps() - 1 ? "" : ", ");
    std::cout << "]\n";

    std::cout << "Avg Wheel Speed: " << vs.averageWheelSpeed()
              << ", Max Engine Temp: " << vs.maxEngineTemp() << "\n";
}

bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) {
    return vs1.isWheelSpeedHigher(vs2);
}
