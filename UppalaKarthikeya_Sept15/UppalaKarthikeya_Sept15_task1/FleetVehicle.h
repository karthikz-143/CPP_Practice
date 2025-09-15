#ifndef FLEETVEHICLE_H
#define FLEETVEHICLE_H

#include <string>
#include <iostream>

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;            // 'A' = Active, 'I' = Inactive
    bool isAvailable;
    std::string driverName;

public:
    // Constructors & Destructor
    FleetVehicle();
    FleetVehicle(int id, float fuel, double distance, char stat, bool available, const std::string& driver);
    ~FleetVehicle();

    // Getters
    int getVehicleID() const;
    float getFuelLevel() const;
    double getDistanceTravelled() const;
    char getStatus() const;
    bool getIsAvailable() const;
    std::string getDriverName() const;

    // Setters
    void setVehicleID(int id);
    void setFuelLevel(float fuel);
    void setDistanceTravelled(double distance);
    void setStatus(char stat);
    void setIsAvailable(bool available);
    void setDriverName(const std::string& driver);

    // Functions
    void updateStatus();
    void displayInfo() const;
};

// Global helper functions
void assignDriver(FleetVehicle& vehicle, const std::string& name);
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount);

#endif
#pragma once

#define FLEETVEHICLE_H  