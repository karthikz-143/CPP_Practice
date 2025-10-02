#include "UppalaKarthikeya_Oct1_Task1_HybridVehicle.h"

// Constructor
HybridVehicle::HybridVehicle(const std::string& name, float eKm, float gKm, float gUsed)
    : modelName(name), electricKm(eKm), gasolineKm(gKm), gasolineUsed(gUsed), tripCount(0)
{
    for (int i = 0; i < 10; i++)
    {
        trips[i] = 0;
    }
}

// Copy constructor 
HybridVehicle::HybridVehicle(const HybridVehicle& other)
{
    modelName = other.modelName;
    electricKm = other.electricKm;
    gasolineKm = other.gasolineKm;
    gasolineUsed = other.gasolineUsed;
    tripCount = other.tripCount;
    for (int i = 0; i < 10; i++)
    {
        trips[i] = other.trips[i];
    }
}
// Operator + (combine vehicles)
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const
{
    HybridVehicle result;
    result.modelName = modelName + "-" + other.modelName;
    result.electricKm = electricKm + other.electricKm;
    result.gasolineKm = gasolineKm + other.gasolineKm;
    result.gasolineUsed = gasolineUsed + other.gasolineUsed;
    result.tripCount = (tripCount > other.tripCount) ? tripCount : other.tripCount;

    for (int i = 0; i < 10; i++)
    {
        result.trips[i] = trips[i] + other.trips[i];
    }
    return result;
}
// Operator == (compare efficiency)
bool HybridVehicle::operator==(const HybridVehicle& other) const
{
    float eff1 = (gasolineUsed != 0.0F) ? ((electricKm + gasolineKm) / gasolineUsed) : 0.0F;
    float eff2 = (other.gasolineUsed != 0.0F) ? ((other.electricKm + other.gasolineKm) / other.gasolineUsed) : 0.0F;
    return (eff1 == eff2);
}

// Operator = (deep copy)
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other)
{
    if (this != &other)
    {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        for (int i = 0; i < 10; i++)
        {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// Operator ++ (prefix increment to add a dummy trip)
HybridVehicle& HybridVehicle::operator++()
{
    if (tripCount < 10)
    {
        trips[tripCount] = 10;  // dummy trip distance
        tripCount++;
    }
    return *this;
}

// Operator [] (subscript to access trip)
int& HybridVehicle::operator[](int index)
{
    if (index >= 0 && index < 10)
    {
        return trips[index];
    }
    else
    {
        std::cerr << "Index out of range. Returning trips[0]." << std::endl;
        return trips[0]; // fallback to prevent crash
    }
}

// Operator () (total distance)
int HybridVehicle::operator()() const
{
    int total = 0;
    for (int i = 0; i < tripCount; i++)
    {
        total += trips[i];
    }
    return static_cast<int>(electricKm + gasolineKm + total);
}

// Operator float (convert to efficiency)
HybridVehicle::operator float() const
{
    return (gasolineUsed != 0.0F) ? ((electricKm + gasolineKm) / gasolineUsed) : 0.0F;
}

// Operator << (print vehicle details)
std::ostream& operator<<(std::ostream& os, const HybridVehicle& hv)
{
    os << "Model: " << hv.modelName
       << ", Electric Km: " << hv.electricKm
       << ", Gasoline Km: " << hv.gasolineKm
       << ", Gasoline Used: " << hv.gasolineUsed
       << ", Efficiency: " << static_cast<float>(hv) << " km/L";
    return os;
}
