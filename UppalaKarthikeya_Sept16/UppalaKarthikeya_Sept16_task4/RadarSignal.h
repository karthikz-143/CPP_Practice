#ifndef RADAR_SIGNAL_H
#define RADAR_SIGNAL_H

#include <iostream>

class RadarSignal {
private:
    int num_channels;           
    float* signal_strengths;    
public:
    // Constructor
    RadarSignal(int numChannels, float* initialSignals);

    // Destructor
    ~RadarSignal();

    // Calculate average signal strength
    float averageSignal() const;

    // Friend functions (global functions)
    friend void printRadarSignal(const RadarSignal& radar);
    friend void boostSignalByValue(RadarSignal radar);     
    friend void boostSignalByReference(RadarSignal& radar); 
};

// Global helper function 
RadarSignal* createRadarSignalHeap(int numChannels, float* signals);

#endif // RADAR_SIGNAL_H
