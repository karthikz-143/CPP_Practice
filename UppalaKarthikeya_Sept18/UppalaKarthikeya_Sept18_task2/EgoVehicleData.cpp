#include "EgoVehicleData.h"
#include <iostream>

EgoVehicleData::EgoVehicleData(int lanes, const float* positions, const float* confidence)
    : num_lanes(lanes) {
    lane_positions = new float[num_lanes];
    sensor_confidence = new float[num_lanes];

    for (int i = 0; i < num_lanes; ++i) {
        lane_positions[i] = positions[i];
        sensor_confidence[i] = confidence[i];
    }
}

EgoVehicleData::~EgoVehicleData() {
    delete[] lane_positions;
    delete[] sensor_confidence;
}

float EgoVehicleData::getAverageLanePosition() const {
    float sum = 0.0f;
    for (int i = 0; i < num_lanes; ++i) {
        sum += lane_positions[i];
    }
    return sum / num_lanes;
}

void EgoVehicleData::updateSensorConfidence(float factor) {
    for (int i = 0; i < num_lanes; ++i) {
        sensor_confidence[i] *= factor;
    }
}

float EgoVehicleData::getTotalSensorConfidence() const {
    float sum = 0.0f;
    for (int i = 0; i < num_lanes; ++i) {
        sum += sensor_confidence[i];
    }
    return sum;
}

void EgoVehicleData::print() const {
    std::cout << "Lane Positions: ";
    for (int i = 0; i < num_lanes; ++i) {
        std::cout << lane_positions[i] << " ";
    }
    std::cout << "\nSensor Confidence: ";
    for (int i = 0; i < num_lanes; ++i) {
        std::cout << sensor_confidence[i] << " ";
    }
    std::cout << "\nAverage Lane Position: " << getAverageLanePosition() << "\n\n";
}

void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest) {
    if (size <= 0) {
        highest = nullptr;
        return;
    }
    highest = &array[0];
    float maxConfidence = array[0].getTotalSensorConfidence();
    for (int i = 1; i < size; ++i) {
        float current = array[i].getTotalSensorConfidence();
        if (current > maxConfidence) {
            highest = &array[i];
            maxConfidence = current;
        }
    }
}

void printEgoVehicleData(const EgoVehicleData& data) {
    data.print();
}

void printHighestConfidenceVehicle(const EgoVehicleData* vehicle) {
    if (vehicle) {
        std::cout << "Vehicle with highest confidence:\n";
        vehicle->print();
    } else {
        std::cout << "No vehicle found\n";
    }
}
