#ifndef CAMERA_CONFIG_H
#define CAMERA_CONFIG_H

#include <iostream>
#include <string>

class CameraConfig {
private:
    int num_modes;
    int* resolution_width;
    int* resolution_height;
public:
    //Constructor
    CameraConfig(int modes, const int widths[], const int heights[]);

    //Copy Constructor
    CameraConfig(const CameraConfig& other);

    //Destructor
    ~CameraConfig();

    //Print Configurations
    void printConfig() const;

    //Compare resolutions
    bool  isHigherResolution(int mode1, int mode2) const;
};
//Global functions
void printCameraConfig(const CameraConfig& config);
bool globalCompareResolution(const CameraConfig& config, int m1,int m2) ;

#endif // CAMERA_CONFIG_H

