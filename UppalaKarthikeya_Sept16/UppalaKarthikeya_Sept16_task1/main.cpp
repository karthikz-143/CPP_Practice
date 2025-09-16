#include "LaneBoundary.h"
#include <iostream>

int main() {
    LaneBoundary lane1(0.015f, 1);
    LaneBoundary lane2(0.023f, 2);

    std::cout << "--- Lane Details ---\n";
    lane1.display();
    lane2.display();

    // Member function comparison
    std::cout << "\n--- Member Function ---\n";
    if (lane1.compareCurvature(lane2)) {
        std::cout << "Lane " << lane1.getLaneId() << " has greater curvature.\n";
    } else if (lane2.compareCurvature(lane1)) {
        std::cout << "Lane " << lane2.getLaneId() << " has greater curvature.\n";
    } else {
        std::cout << "Both lanes have equal curvature.\n";
    }

    // Global function comparison
    std::cout << "\n--- Global Function ---\n";
    printLaneComparison(lane1, lane2);

    return 0;
}
