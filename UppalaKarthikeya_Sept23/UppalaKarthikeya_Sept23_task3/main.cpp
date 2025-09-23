#include <iostream>
#include "Airline.h"

int main() {
    bool seats[10] = {false}; // all seats start empty
    int choice;

    std::cout << "Welcome to Airline Reservation System\n";

    for (int i = 0; i < 10; i++) { // only 10 seats total
        std::cout << "\nPlease type 1 for First Class or 2 for Economy: ";
        std::cin >> choice;
        assignSeat(seats, choice);
    }

    std::cout << "All seats are booked. Next flight leaves in 3 hours.\n";
    return 0;
}
