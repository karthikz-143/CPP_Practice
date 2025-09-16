#ifndef LANE_BOUNDARY_H
#define LANE_BOUNDARY_H

#include <iostream>

class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:
    // Constructor
    LaneBoundary(float c, int id);

    // Getters
    float getCurvature() const;
    int getLaneId() const;   
    // Compare curvature 
    bool compareCurvature(const LaneBoundary& other) const;

    // Show lane details
    void display() const;
};

// Global functions
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2);
void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2);

#endif
