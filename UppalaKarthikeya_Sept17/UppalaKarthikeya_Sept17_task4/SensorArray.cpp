#include "SensorArray.h"

double SensorArray::global_max_temperature = -1e9;

SensorArray::SensorArray(int id, SensorType t, const double* readings, int n)
    : sensor_id(id), type(t), num_readings(n) {
    temperature_readings = new double[num_readings];
    for (int i = 0; i < num_readings; i++) {
        temperature_readings[i] = readings[i];
        if (readings[i] > global_max_temperature) {
            global_max_temperature = readings[i];
        }
    }
}

SensorArray::~SensorArray() {
    delete[] temperature_readings;
}

double SensorArray::getMaxTemperature() const {
    double maxTemp = temperature_readings[0];
    for (int i = 1; i < num_readings; i++) {
        if (temperature_readings[i] > maxTemp) {
            maxTemp = temperature_readings[i];
        }
    }
    return maxTemp;
}

void SensorArray::printSensorInfo() const {
    std::cout << "Sensor ID: " << sensor_id
              << ", Type: " << sensorTypeToString(type)
              << ", Max Temperature: " << getMaxTemperature() << "\n";
}

double SensorArray::getGlobalMaxTemperature() {
    return global_max_temperature;
}

const char* sensorTypeToString(SensorType t) {
    switch (t) {
        case LIDAR: return "LIDAR";
        case RADAR: return "RADAR";
        case CAMERA: return "CAMERA";
        default: return "UNKNOWN";
    }
}

void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}

void printAllSensors(const SensorArray* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].printSensorInfo();
    }
}
