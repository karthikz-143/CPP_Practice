#ifndef AEROSPACE_COMPONENT_H
#define AEROSPACE_COMPONENT_H

#include <string>
#include <iostream>

// Enum for component type
enum ComponentType
{
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

// Enum for component status
enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

// Convert enums to string for printing
std::string componentTypeToString(ComponentType type);
std::string componentStatusToString(ComponentStatus status);

class AerospaceComponent
{
private:
    int componentIdentifier;
    double componentEfficiency;
    std::string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    // Constructors
    AerospaceComponent(); // Default
    AerospaceComponent(int id, double efficiency, const std::string& manufacturer,
                       ComponentType type, ComponentStatus status);

    ~AerospaceComponent(); // Destructor

    // Getters
    int getComponentIdentifier() const;
    double getComponentEfficiency() const;
    std::string getComponentManufacturer() const;
    ComponentType getComponentType() const;
    ComponentStatus getComponentStatus() const;

    // Setters
    void setComponentIdentifier(int id);
    void setComponentEfficiency(double efficiency);
    void setComponentManufacturer(const std::string& manufacturer);
    void setComponentType(ComponentType type);
    void setComponentStatus(ComponentStatus status);

    // Core functionality
    void updateStatus();
    void simulateUsage(int hours);
    void performMaintenanceCheck() const;
    void boostEfficiency();
    void displayDetails() const;
};

// Global helpers
void assignManufacturer(AerospaceComponent& component, const std::string& manufacturerName);
bool isEfficient(const AerospaceComponent& component);
bool isSameType(const AerospaceComponent& a, const AerospaceComponent& b);
bool isSameStatus(const AerospaceComponent& a, const AerospaceComponent& b);
void printFormattedComponentList(const AerospaceComponent list[], int size);
int searchComponentByIdentifier(const AerospaceComponent list[], int size, int id);

#endif
