#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include <iostream>

class Pedestrian {
    unsigned int pedestrian_id;
    float distance_from_vehicle; 
public:
    Pedestrian(unsigned int id,float distance);
    void updateDistance(float newDistance);
    float getDistance() const;
    unsigned int getPedestrianId() const;
    void displayPedestrianInfo() const;
};
//Global functions
void findClosestPedestrian(Pedestrian* arr, unsigned int size, const Pedestrian*& closest);
void printClosestPedestrian(const Pedestrian* closest);
#endif // PEDESTRIAN_H