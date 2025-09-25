#include "Flight.h"
#include <iostream>

// Constructor
Flight::Flight(std::string air, std::string num, std::string model,
               std::string org, std::string dest, std::string dep, std::string arr,
               double altitude, double speed, std::string dir, FlightStatus stat)
    : airline(air), flightNumber(num), makeModel(model),
      origin(org), destination(dest), departureTime(dep), arrivalTime(arr),
      currentAltitude(altitude), currentSpeed(speed), direction(dir),
      newAltitude(altitude), status(stat) {}

// Change altitude
void Flight::changeAltitude(double altitude)
{
    std::cout << airline << " " << flightNumber
              << " changing altitude from " << currentAltitude
              << " to " << altitude << " feet." << std::endl;

    status = FlightStatus::CHANGING_ALTITUDE;
    newAltitude = altitude;
    currentAltitude = altitude;
}

// Reduce speed
void Flight::reduceSpeed(double speed)
{
    std::cout << airline << " " << flightNumber
              << " reducing speed from " << currentSpeed
              << " to " << speed << " knots." << std::endl;

    currentSpeed = speed;
}

// Begin landing
void Flight::beginLandingApproach()
{
    std::cout << airline << " " << flightNumber
              << " beginning landing approach at destination "
              << destination << "." << std::endl;

    status = FlightStatus::DESCENDING;
}

std::string Flight::statusToString() const
{
    switch (status)
    {
    case FlightStatus::PARKED: return "Parked";
    case FlightStatus::TAXIING: return "Taxiing";
    case FlightStatus::WAITING_TAKEOFF: return "Waiting for Takeoff";
    case FlightStatus::TAKING_OFF: return "Taking Off";
    case FlightStatus::CLIMBING: return "Climbing";
    case FlightStatus::CRUISING: return "Cruising";
    case FlightStatus::CHANGING_ALTITUDE: return "Changing Altitude";
    case FlightStatus::DESCENDING: return "Descending";
    case FlightStatus::LANDING: return "Landing";
    case FlightStatus::AT_GATE: return "At the Gate";
    default: return "Unknown";
    }
}

// Flight details
std::string Flight::toString() const
{
    return "Airline: " + airline + " | Flight: " + flightNumber +
           " | Model: " + makeModel +
           " | From: " + origin + " | To: " + destination +
           " | Departure: " + departureTime +
           " | Arrival: " + arrivalTime +
           " | Altitude: " + std::to_string(currentAltitude) +
           " ft | Speed: " + std::to_string(currentSpeed) +
           " knots | Direction: " + direction +
           " | Status: " + statusToString();
}
