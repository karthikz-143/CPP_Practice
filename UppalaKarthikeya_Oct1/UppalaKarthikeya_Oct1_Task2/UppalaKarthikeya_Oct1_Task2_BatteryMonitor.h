#ifndef UPPALAKARTHIKEYA_OCT2_BATTERYMONITOR_H
#define UPPALAKARTHIKEYA_OCT2_BATTERYMONITOR_H

#include <iostream>
#include <string>

class BatteryMonitor
{
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;
    float originalCapacity;
    bool isActive;
    int* tripDistances;
    int tripCount;

public:
    BatteryMonitor(const std::string& id, int cycles, float capacity, float origCap, bool active, int trips);
    BatteryMonitor(const BatteryMonitor& other);        // deep copy
    BatteryMonitor& operator=(const BatteryMonitor& other); // deep copy with self-assignment check
    ~BatteryMonitor();                                  // release memory

    bool operator>(const BatteryMonitor& other) const;
    bool operator<(const BatteryMonitor& other) const;
    BatteryMonitor& operator+=(int cycles);             // simulate cycles
    int& operator[](int index);
    bool operator!() const;                             // check inactive
    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm);
};

#endif
