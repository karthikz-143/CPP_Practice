#include "CameraConfig.h"

int main() {
    // Sample Data
    int widths[3]  = {1920, 1280, 3840};
    int heights[3] = {1080, 2160, 2160};

    // Create CameraConfig object
    CameraConfig camConfig(3, widths, heights);
    printCameraConfig(camConfig);

    // Compare resolutions using member function
    std::cout << "\nComparison using member function:\n";
    if (camConfig.isHigherResolution(0, 2))
        std::cout << "Mode 0 has higher resolution than Mode 2\n";
    else
        std::cout << "Mode 2 has higher resolution than Mode 0\n";

    // Compare resolutions using global function
    std::cout << "\nComparison using global function:\n";
    if (globalCompareResolution(camConfig, 1, 2))
        std::cout << "Mode 1 has higher resolution than Mode 2\n";
    else
        std::cout << "Mode 2 has higher resolution than Mode 1\n";

    return 0;
}
