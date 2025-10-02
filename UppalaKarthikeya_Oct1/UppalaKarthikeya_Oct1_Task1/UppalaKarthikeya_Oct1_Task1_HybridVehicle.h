#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <iostream>
#include <string>

class HybridVehicle
{
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10]; 
    int tripCount;

public:
    // Constructor
    HybridVehicle(const std::string& name = "", float eKm = 0.0F, float gKm = 0.0F, float gUsed = 0.0F);

    // Copy constructor
    HybridVehicle(const HybridVehicle& other);

    // Operator Overloads
    HybridVehicle operator+(const HybridVehicle& other) const;   
    bool operator==(const HybridVehicle& other) const;           
    HybridVehicle& operator=(const HybridVehicle& other);        
    HybridVehicle& operator++();                                 
    int& operator[](int index);                                  
    int operator()() const;                                      
    operator float() const;                                      

    // Stream insertion
    friend std::ostream& operator<<(std::ostream& os, const HybridVehicle& hv);
};

#endif
