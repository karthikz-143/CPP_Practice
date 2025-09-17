#include "Pedestrian.h"
#include <iostream>
#include <iomanip>

Pedestrian::Pedestrian(unsigned int id, float distance) 
    : pedestrian_id(id), distance_from_vehicle(distance) {
        if (distance < 0) {
            std::cerr << "Distance cannot be negative. Setting to 0." << std::endl;
            distance_from_vehicle = 0.0f;
        }
    }

//update distance
void Pedestrian::updateDistance(float newDistance) {
    if (newDistance < 0) {
        std::cerr << "Distance cannot be negative. Update ignored." << std::endl;
        return;
    }
    distance_from_vehicle = newDistance;
}

float Pedestrian::getDistance() const {
    return distance_from_vehicle;
}

unsigned int Pedestrian::getPedestrianId() const {
    return pedestrian_id;
}

void Pedestrian::displayPedestrianInfo() const {
    std::cout << "Pedestrian ID: " << pedestrian_id
              << ", Distance: " << std::fixed << std::setprecision(1)
              << distance_from_vehicle << " meters\n";
}

//Closest pedestrian
void findClosestPedestrian(Pedestrian* arr, unsigned int size, const Pedestrian*& closest) {
    if (size == 0) {
        closest = nullptr;
        return;
    }
    closest = &arr[0];
    for (unsigned int i = 1; i < size; ++i) {
        if (arr[i].getDistance() < closest->getDistance()) {
            closest = &arr[i];
        }
    }
}

void printClosestPedestrian(const Pedestrian* closest) {
    if (closest) {
        std::cout << "Closest Pedestrian Information:\n";
        closest->displayPedestrianInfo();
    } else {
        std::cout << "No pedestrians available to compare.\n";
    }
}