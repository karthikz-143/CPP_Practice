#include "AerospaceComponent.h"
#include <iomanip>

// Enum → String
std::string componentTypeToString(ComponentType type) {
    switch (type) {
        case COMPONENT_TYPE_ENGINE: return "Engine";
        case COMPONENT_TYPE_AVIONICS: return "Avionics";
        case COMPONENT_TYPE_LANDING_GEAR: return "Landing Gear";
        case COMPONENT_TYPE_FUEL_SYSTEM: return "Fuel System";
        default: return "Unknown";
    }
}

std::string componentStatusToString(ComponentStatus status) {
    switch (status) {
        case COMPONENT_STATUS_OPERATIONAL: return "Operational";
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED: return "Maintenance Required";
        case COMPONENT_STATUS_FAILED: return "Failed";
        default: return "Unknown";
    }
}

// Constructors
AerospaceComponent::AerospaceComponent()
    : componentIdentifier(0), componentEfficiency(100.0), componentManufacturer("Unknown"),
      componentType(COMPONENT_TYPE_ENGINE), componentStatus(COMPONENT_STATUS_OPERATIONAL) {}

AerospaceComponent::AerospaceComponent(int id, double efficiency, const std::string& manufacturer,
                                       ComponentType type, ComponentStatus status)
    : componentIdentifier(id), componentEfficiency(efficiency), componentManufacturer(manufacturer),
      componentType(type), componentStatus(status) {}

AerospaceComponent::~AerospaceComponent() {
    std::cout << "Component " << componentIdentifier << " destroyed.\n";
}

// Getters
int AerospaceComponent::getComponentIdentifier() const { return componentIdentifier; }
double AerospaceComponent::getComponentEfficiency() const { return componentEfficiency; }
std::string AerospaceComponent::getComponentManufacturer() const { return componentManufacturer; }
ComponentType AerospaceComponent::getComponentType() const { return componentType; }
ComponentStatus AerospaceComponent::getComponentStatus() const { return componentStatus; }

// Setters
void AerospaceComponent::setComponentIdentifier(int id) { componentIdentifier = id; }
void AerospaceComponent::setComponentEfficiency(double efficiency) { componentEfficiency = efficiency; }
void AerospaceComponent::setComponentManufacturer(const std::string& manufacturer) { componentManufacturer = manufacturer; }
void AerospaceComponent::setComponentType(ComponentType type) { componentType = type; }
void AerospaceComponent::setComponentStatus(ComponentStatus status) { componentStatus = status; }

// Core methods
void AerospaceComponent::updateStatus() {
    if (componentEfficiency < 50.0) {
        componentStatus = COMPONENT_STATUS_FAILED;
    } else if (componentEfficiency < 80.0) {
        componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
    } else {
        componentStatus = COMPONENT_STATUS_OPERATIONAL;
    }
}

void AerospaceComponent::simulateUsage(int hours) {
    for (int i = 0; i < hours; i++) {
        componentEfficiency -= 0.5;
        if (componentEfficiency < 0.0) {
            componentEfficiency = 0.0;
            break;
        }
    }
    updateStatus();
}

void AerospaceComponent::performMaintenanceCheck() const {
    std::cout << "Maintenance check for Component " << componentIdentifier << ": "
              << componentStatusToString(componentStatus) << "\n";
}

void AerospaceComponent::boostEfficiency() {
    while (componentEfficiency < 100.0) {
        componentEfficiency += 1.0;
        if (componentEfficiency > 100.0) componentEfficiency = 100.0;
    }
    updateStatus();
}

void AerospaceComponent::displayDetails() const {
    std::cout << "\nComponent ID: " << componentIdentifier
              << "\nEfficiency: " << componentEfficiency << "%"
              << "\nManufacturer: " << componentManufacturer
              << "\nType: " << componentTypeToString(componentType)
              << "\nStatus: " << componentStatusToString(componentStatus)
              << "\n";
}

// Global helpers
void assignManufacturer(AerospaceComponent& component, const std::string& name) {
    component.setComponentManufacturer(name);
}

bool isEfficient(const AerospaceComponent& c) { return c.getComponentEfficiency() > 85.0; }
bool isSameType(const AerospaceComponent& a, const AerospaceComponent& b) { return a.getComponentType() == b.getComponentType(); }
bool isSameStatus(const AerospaceComponent& a, const AerospaceComponent& b) { return a.getComponentStatus() == b.getComponentStatus(); }

void printFormattedComponentList(const AerospaceComponent list[], int size) {
    std::cout << "\nID   Efficiency   Manufacturer       Type         Status\n";
    std::cout << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << list[i].getComponentIdentifier() << "    "
                  << list[i].getComponentEfficiency() << "%     "
                  << list[i].getComponentManufacturer() << "      "
                  << componentTypeToString(list[i].getComponentType()) << "      "
                  << componentStatusToString(list[i].getComponentStatus()) << "\n";
    }
}

int searchComponentByIdentifier(const AerospaceComponent list[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (list[i].getComponentIdentifier() == id) return i;
    }
    return -1;
}
