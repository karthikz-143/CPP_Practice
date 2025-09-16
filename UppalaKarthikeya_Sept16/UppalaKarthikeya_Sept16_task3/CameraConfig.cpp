#include "CameraConfig.h"

//Constructor
CameraConfig::CameraConfig(int modes, const int widths[], const int heights[]) : num_modes(modes)
{
    resolution_width = new int[num_modes];
    resolution_height = new int[num_modes];
    for (int i = 0; i < num_modes; i++) {
        resolution_width[i] = widths[i];
        resolution_height[i] = heights[i];
    }
}

//copy constructor
CameraConfig::CameraConfig(const CameraConfig& other) : num_modes(other.num_modes)
{
    resolution_width = new int[num_modes];
    resolution_height = new int[num_modes];
    for (int i = 0; i < num_modes; i++) {
        resolution_width[i] = other.resolution_width[i];
        resolution_height[i] = other.resolution_height[i];
    }
}

//Destructor
CameraConfig::~CameraConfig()
{
    delete[] resolution_width;
    delete[] resolution_height;
}

//Print Configurations
void CameraConfig::printConfig() const
{
    std::cout << "Camera Modes Configurations:\n";
    for (int i = 0; i < num_modes; i++) {
        std::cout << "Mode " << i + 1 << ": " 
        << resolution_width[i] << "x" 
        << resolution_height[i] << "\n";
    }
}

//Compare resolutions
bool CameraConfig::isHigherResolution(int mode1, int mode2) const {
    int res1 = resolution_width[mode1] * resolution_height[mode1];
    int res2 = resolution_width[mode2] * resolution_height[mode2];
    return res1 > res2;

}
//Global functions
void printCameraConfig(const CameraConfig& config) {
    config.printConfig();
}

bool globalCompareResolution(const CameraConfig& config, int m1,int m2) {
    return config.isHigherResolution(m1, m2);
}