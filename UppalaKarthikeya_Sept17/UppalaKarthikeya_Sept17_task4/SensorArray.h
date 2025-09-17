#ifndef SENSORARRAY_H
#define SENSORARRAY_H

#include <iostream>

enum SensorType { LIDAR, RADAR, CAMERA };

class SensorArray {
private:
    int sensor_id;
    SensorType type;
    double* temperature_readings;
    int num_readings;
    static double global_max_temperature;

public:
    SensorArray(int id, SensorType t, const double* readings, int n);
    ~SensorArray();

    double getMaxTemperature() const;
    void printSensorInfo() const;

    static double getGlobalMaxTemperature();
    int getId() const { return sensor_id; }
    SensorType getType() const { return type; }
};

const char* sensorTypeToString(SensorType t);
void printSensor(const SensorArray& s);
void printAllSensors(const SensorArray* arr, int size);

#endif
