#ifndef VEHICLE_STATUS_H
#define VEHICLE_STATUS_H

class VehicleStatus {
public:
    VehicleStatus(int numWheels, const float* wheelSpeedData, int numTemps, const float* engineTempData);
    ~VehicleStatus();

    float averageWheelSpeed() const;
    float maxEngineTemp() const;
    bool isWheelSpeedHigher(const VehicleStatus& other) const;

    int getNumWheels() const { return num_wheels; }
    const float* getWheelSpeed() const { return wheel_speed; }
    int getNumTemps() const { return num_temps; }
    const float* getEngineTemp() const { return engine_temp; }

private:
    int num_wheels;
    float* wheel_speed;
    int num_temps;
    float* engine_temp;

    float findMaxWheelSpeed() const;
};

// Global Functions
void printVehicleStatus(const VehicleStatus& vs);
bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2);

#endif
