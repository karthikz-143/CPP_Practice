#include "SatelliteData.h"
#include <iostream>

int SatelliteData::active_satellites = 0;

// Constructor
SatelliteData::SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus st)
    : satellite_id(id), num_antennas(antennas), orbital_altitude(altitude), status(st) {
    signal_strength = new float[num_antennas];
    for (int i = 0; i < num_antennas; ++i) {
        signal_strength[i] = signals[i];
    }
    active_satellites++;
}

SatelliteData::SatelliteData(const SatelliteData& other)
    : satellite_id(other.satellite_id), num_antennas(other.num_antennas),
      orbital_altitude(other.orbital_altitude), status(other.status) {
    signal_strength = new float[num_antennas];
    for (int i = 0; i < num_antennas; ++i) {
        signal_strength[i] = other.signal_strength[i];
    }
    active_satellites++;
}

// Destructor
SatelliteData::~SatelliteData() {
    delete[] signal_strength;
    active_satellites--;
}

float SatelliteData::getAverageSignalStrength() const {
    float sum = 0.0f;
    for (int i = 0; i < num_antennas; ++i) {
        sum += signal_strength[i];
    }
    return sum / num_antennas;
}

void SatelliteData::boostSignal(float factor) {
    for (int i = 0; i < num_antennas; ++i) {
        signal_strength[i] *= factor;
    }
}

void SatelliteData::boostSignal(float factor, float threshold) {
    for (int i = 0; i < num_antennas; ++i) {
        if (signal_strength[i] < threshold) {
            signal_strength[i] *= factor;
        }
    }
}

int SatelliteData::getActiveSatelliteCount() {
    return active_satellites;
}

void SatelliteData::setStatus(SatelliteStatus new_status) {
    status = new_status;
}

std::string SatelliteData::getStatusString() const {
    switch (status) {
        case OPERATIONAL: return "Operational";
        case MAINTENANCE: return "Maintenance";
        case DECOMMISSIONED: return "Decommissioned";
        default: return "Unknown";
    }
}

// Global functions
void printSatelliteData(const SatelliteData& sd) {
    std::cout << "Satellite ID: " << sd.getId() << "\n";
    std::cout << "Altitude: " << sd.getAltitude() << " km\n";
    std::cout << "Signal Strengths: ";
    for (int i = 0; i < sd.getNumAntennas(); ++i) {
        std::cout << sd.getSignals()[i] << " ";
    }
    std::cout << "\nStatus: " << sd.getStatusString() << "\n";
    std::cout << "Average Signal Strength: " << sd.getAverageSignalStrength() << "\n\n";
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAltitude() > s2.getAltitude();
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source); 
}

void printActiveSatelliteCount() {
    std::cout << "Active Satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";
}

void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold) {
        sd.setStatus(MAINTENANCE);
    }
}
