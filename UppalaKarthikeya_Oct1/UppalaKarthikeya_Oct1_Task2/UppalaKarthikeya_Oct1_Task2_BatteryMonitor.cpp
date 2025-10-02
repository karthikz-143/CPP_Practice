#include "UppalaKarthikeya_Oct2_Task2_BatteryMonitor.h"

BatteryMonitor::BatteryMonitor(const std::string& id, int cycles, float capacity, float origCap, bool active, int trips)
    : scooterID(id), chargeCycles(cycles), batteryCapacity(capacity), originalCapacity(origCap), isActive(active), tripCount(trips)
{
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; ++i) tripDistances[i] = 0;
}

BatteryMonitor::BatteryMonitor(const BatteryMonitor& other)
    : scooterID(other.scooterID), chargeCycles(other.chargeCycles), batteryCapacity(other.batteryCapacity),
      originalCapacity(other.originalCapacity), isActive(other.isActive), tripCount(other.tripCount)
{
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; ++i) tripDistances[i] = other.tripDistances[i];
}

BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other)
{
    if (this != &other)
    {
        delete[] tripDistances;
        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i) tripDistances[i] = other.tripDistances[i];
    }
    return *this;
}

BatteryMonitor::~BatteryMonitor()
{
    delete[] tripDistances;
}

bool BatteryMonitor::operator>(const BatteryMonitor& other) const
{
    return (batteryCapacity / originalCapacity) > (other.batteryCapacity / other.originalCapacity);
}

bool BatteryMonitor::operator<(const BatteryMonitor& other) const
{
    return (batteryCapacity / originalCapacity) < (other.batteryCapacity / other.originalCapacity);
}

BatteryMonitor& BatteryMonitor::operator+=(int cycles)
{
    chargeCycles += cycles;
    batteryCapacity -= (cycles * 0.01F);  // degrade 0.01 kWh per cycle
    if (batteryCapacity < 0.0F) batteryCapacity = 0.0F;
    return *this;
}

int& BatteryMonitor::operator[](int index)
{
    if (index >= 0 && index < tripCount)
    {
        return tripDistances[index];
    }
    else
    {
        std::cerr << "Index out of range. Returning first element." << std::endl;
        return tripDistances[0];
    }
}

bool BatteryMonitor::operator!() const
{
    return !isActive;
}

std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm)
{
    float health = (bm.originalCapacity != 0.0F) ? (bm.batteryCapacity / bm.originalCapacity) * 100.0F : 0.0F;
    os << "ScooterID: " << bm.scooterID
       << ", Charge Cycles: " << bm.chargeCycles
       << ", Capacity: " << bm.batteryCapacity << " kWh"
       << ", Health: " << health << "%"
       << ", Active: " << (bm.isActive ? "Yes" : "No");
    return os;
}
