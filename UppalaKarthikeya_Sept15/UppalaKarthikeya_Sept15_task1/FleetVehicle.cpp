#include "FleetVehicle.h"

// Default constructor
FleetVehicle::FleetVehicle() 
    : vehicleID(0), fuelLevel(50), distanceTravelled(0), 
      status('A'), isAvailable(true), driverName("Unassigned") {}

// Parameterized constructor
FleetVehicle::FleetVehicle(int id, float fuel, double distance, char stat, bool available, const std::string& driver)
    : vehicleID(id), fuelLevel(fuel), distanceTravelled(distance), 
      status(stat), isAvailable(available), driverName(driver) {}

// Destructor
FleetVehicle::~FleetVehicle() {
    std::cout << "Vehicle ID " << vehicleID << " removed.\n";
}

// Getters
int FleetVehicle::getVehicleID() const { return vehicleID; }
float FleetVehicle::getFuelLevel() const { return fuelLevel; }
double FleetVehicle::getDistanceTravelled() const { return distanceTravelled; }
char FleetVehicle::getStatus() const { return status; }
bool FleetVehicle::getIsAvailable() const { return isAvailable; }
std::string FleetVehicle::getDriverName() const { return driverName; }

// Setters
void FleetVehicle::setVehicleID(int id) { vehicleID = id; }
void FleetVehicle::setFuelLevel(float fuel) { fuelLevel = fuel; }
void FleetVehicle::setDistanceTravelled(double distance) { distanceTravelled = distance; }
void FleetVehicle::setStatus(char stat) { status = stat; }
void FleetVehicle::setIsAvailable(bool available) { isAvailable = available; }
void FleetVehicle::setDriverName(const std::string& driver) { driverName = driver; }

// Functions
void FleetVehicle::updateStatus() {
    status = (fuelLevel < 10 || !isAvailable) ? 'I' : 'A';
}

void FleetVehicle::displayInfo() const {
    std::cout << "\n--- Vehicle Info ---\n";
    std::cout << "ID: " << vehicleID << "\n";
    std::cout << "Fuel: " << fuelLevel << " L\n";
    std::cout << "Distance: " << distanceTravelled << " km\n";
    std::cout << "Status: " << (status == 'A' ? "Active" : "Inactive") << "\n";
    std::cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
    std::cout << "Driver: " << driverName << "\n";
}

// Global helpers
void assignDriver(FleetVehicle& vehicle, const std::string& name) {
    vehicle.setDriverName(name);
    std::cout << "Driver " << name << " assigned to vehicle " << vehicle.getVehicleID() << "\n";
}

void refuelVehicle(FleetVehicle& vehicle, float fuelAmount) {
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    std::cout << "Vehicle " << vehicle.getVehicleID() 
              << " refueled. Current fuel: " << vehicle.getFuelLevel() << " L\n";
}
