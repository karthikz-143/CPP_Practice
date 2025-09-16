#include "LaneBoundary.h"
#include <iostream>   

// Constructor
LaneBoundary::LaneBoundary(float c, int id) : curvature(c), lane_id(id) {}

// Getters
float LaneBoundary::getCurvature() const { return curvature; }
int LaneBoundary::getLaneId() const { return lane_id; }   

// Compare curvature
bool LaneBoundary::compareCurvature(const LaneBoundary& other) const {
    return this->curvature > other.curvature;
}

// Display lane 
void LaneBoundary::display() const {
    std::cout << "Lane " << lane_id << " | Curvature: " << curvature << "\n";
}

// Global function
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    return lane1.getCurvature() > lane2.getCurvature();
}

// Global function: print comparison
void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    std::cout << "Comparing Lane " << lane1.getLaneId() << " and Lane " << lane2.getLaneId() << ":\n";

    if (lane1.getCurvature() > lane2.getCurvature()) {
        std::cout << "Lane " << lane1.getLaneId() << " has greater curvature.\n";
    } else if (lane2.getCurvature() > lane1.getCurvature()) {
        std::cout << "Lane " << lane2.getLaneId() << " has greater curvature.\n";
    } else {
        std::cout << "Both lanes have equal curvature.\n";
    }
    std::cout << "-----------------------------\n";
}
