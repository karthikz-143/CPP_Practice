#ifndef SATELLITEDATA_H
#define SATELLITEDATA_H

#include <string>

enum SatelliteStatus {
    OPERATIONAL,
    MAINTENANCE,
    DECOMMISSIONED
};

class SatelliteData {
private:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

public:
    // Constructor
    SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus st);
    SatelliteData(const SatelliteData& other);
    ~SatelliteData();

    // Member functions
    float getAverageSignalStrength() const;
    void boostSignal(float factor);
    void boostSignal(float factor, float threshold);
    static int getActiveSatelliteCount();
    void setStatus(SatelliteStatus new_status);
    std::string getStatusString() const;

    // Getters
    int getId() const { return satellite_id; }
    float getAltitude() const { return orbital_altitude; }
    int getNumAntennas() const { return num_antennas; }
    const float* getSignals() const { return signal_strength; }
    SatelliteStatus getStatus() const { return status; }
};

// Global functions
void printSatelliteData(const SatelliteData& sd);
bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2);
void cloneSatellite(const SatelliteData& source, SatelliteData*& target);
void printActiveSatelliteCount();
void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold);

#endif
