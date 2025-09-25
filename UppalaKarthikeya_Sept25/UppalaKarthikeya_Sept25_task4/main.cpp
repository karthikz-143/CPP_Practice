#include <iostream>
#include "Flight.h"

int main()
{
    std::cout << "===== Air Traffic Control Simulator =====" << std::endl;

    // Create 3 flights in different states
    Flight flight1("Delta", "DL123", "Boeing 737", "ATL", "LAX", "08:00", "11:00",
                   0, 0, "North", FlightStatus::PARKED);

    Flight flight2("United", "UA456", "Airbus A320", "ORD", "MIA", "09:30", "13:00",
                   0, 0, "East", FlightStatus::WAITING_TAKEOFF);

    Flight flight3("American", "AA789", "Boeing 777", "JFK", "LHR", "18:00", "06:00",
                   35000, 550, "East", FlightStatus::CRUISING);

    // Print initial details
    std::cout << "\nInitial Flight Statuses:\n";
    std::cout << flight1.toString() << std::endl;
    std::cout << flight2.toString() << std::endl;
    std::cout << flight3.toString() << std::endl;

    std::cout << "\n=== ATC Commands ===\n";

    // Simulate ATC commands
    flight2.changeAltitude(10000);  
    flight2.reduceSpeed(250);
    flight3.changeAltitude(28000);  
    flight3.beginLandingApproach();

    std::cout << "\nUpdated Flight Statuses:\n";
    std::cout << flight1.toString() << std::endl;
    std::cout << flight2.toString() << std::endl;
    std::cout << flight3.toString() << std::endl;

    return 0;
}
