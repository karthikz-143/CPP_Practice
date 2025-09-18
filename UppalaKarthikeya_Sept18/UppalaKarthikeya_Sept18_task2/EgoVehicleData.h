#ifndef EGOVEHICLEDATA_H
#define EGOVEHICLEDATA_H

class EgoVehicleData {
private:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;

public:
    EgoVehicleData(int lanes, const float* positions, const float* confidence);
    ~EgoVehicleData();

    float getAverageLanePosition() const;
    void updateSensorConfidence(float factor);
    float getTotalSensorConfidence() const;
    void print() const;
};

// Global functions
void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest);
void printEgoVehicleData(const EgoVehicleData& data);
void printHighestConfidenceVehicle(const EgoVehicleData* vehicle);

#endif
