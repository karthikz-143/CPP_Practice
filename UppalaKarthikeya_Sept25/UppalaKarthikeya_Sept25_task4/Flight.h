#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
enum class FlightStatus
{
    PARKED,
    TAXIING,
    WAITING_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    CHANGING_ALTITUDE,
    DESCENDING,
    LANDING,
    AT_GATE
};

class Flight
{
private:
    std::string airline;
    std::string flightNumber;
    std::string makeModel;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;

    double currentAltitude;
    double currentSpeed;
    std::string direction;

    double newAltitude;   // target altitude after ATC command
    FlightStatus status;

public:
    // Constructor
    Flight(std::string air, std::string num, std::string model,
           std::string org, std::string dest, std::string dep, std::string arr,
           double altitude, double speed, std::string dir, FlightStatus stat);

    // Behaviors
    void changeAltitude(double altitude);
    void reduceSpeed(double speed);
    void beginLandingApproach();

    // Utility
    std::string statusToString() const;
    std::string toString() const;

    // Getters/Setters
    double getCurrentAltitude() const { return currentAltitude; }
    double getCurrentSpeed() const { return currentSpeed; }
    std::string getAirline() const { return airline; }
    std::string getFlightNumber() const { return flightNumber; }
};

#endif // FLIGHT_H
