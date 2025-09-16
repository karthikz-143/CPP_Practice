#include "RadarSignal.h"

// Constructor
RadarSignal::RadarSignal(int numChannels, float* initialSignals)
    : num_channels(numChannels) 
{
    signal_strengths = new float[num_channels];
    for (int i = 0; i < num_channels; ++i) {
        signal_strengths[i] = initialSignals[i];
    }
}

// Destructor: free memory
RadarSignal::~RadarSignal() {
    delete[] signal_strengths;
    signal_strengths = nullptr;
}

// Calculate average signal strength
float RadarSignal::averageSignal() const {
    if (num_channels == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < num_channels; ++i) {
        sum += signal_strengths[i];
    }
    return sum / num_channels;
}

// Print all signal strengths
void printRadarSignal(const RadarSignal& radar) {
    std::cout << "Radar Signals: [ ";
    for (int i = 0; i < radar.num_channels; ++i) {
        std::cout << radar.signal_strengths[i] << (i == radar.num_channels - 1 ? " " : ", ");
    }
    std::cout << "]" << std::endl;
}

// Global function: boost signals by +5 
void boostSignalByValue(RadarSignal radar) {
    for (int i = 0; i < radar.num_channels; ++i) {
        radar.signal_strengths[i] += 5.0f;
    }
    std::cout << "(Inside boostSignalByValue - copy boosted)" << std::endl;
    printRadarSignal(radar);
}

// Global function: boost signals by +5 
void boostSignalByReference(RadarSignal& radar) {
    for (int i = 0; i < radar.num_channels; ++i) {
        radar.signal_strengths[i] += 5.0f;
    }
    std::cout << "(Inside boostSignalByReference - original boosted)" << std::endl;
    printRadarSignal(radar);
}

// Create RadarSignal object on heap
RadarSignal* createRadarSignalHeap(int numChannels, float* signals) {
    return new RadarSignal(numChannels, signals);
}
