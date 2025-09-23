#include <iostream>
#include "Airline.h"

int findAvailableSeat(bool seats[], int start, int end) {
    for (int i = start; i <= end; i++) {
        if (!seats[i]) {
            return i;
        }
    }
    return -1; // no available seat
}

void assignSeat(bool seats[], int choice) {
    int seatNumber = -1;

    if (choice == 1) {
        seatNumber = findAvailableSeat(seats, 0, 4); // seats 1–5
        if (seatNumber == -1) {
            std::cout << "First Class is full. Would you like Economy instead? (y/n): ";
            char response;
            std::cin >> response;
            if (response == 'y' || response == 'Y') {
                seatNumber = findAvailableSeat(seats, 5, 9);
            } else {
                std::cout << "Next flight leaves in 3 hours.\n";
                return;
            }
        }
    } else if (choice == 2) {
        seatNumber = findAvailableSeat(seats, 5, 9); // seats 6–10
        if (seatNumber == -1) {
            std::cout << "Economy is full. Would you like First Class instead? (y/n): ";
            char response;
            std::cin >> response;
            if (response == 'y' || response == 'Y') {
                seatNumber = findAvailableSeat(seats, 0, 4);
            } else {
                std::cout << "Next flight leaves in 3 hours.\n";
                return;
            }
        }
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }

    if (seatNumber != -1) {
        seats[seatNumber] = true; // mark seat as taken
        printBoardingPass(seatNumber + 1); 
    }
}

// Print boarding pass
void printBoardingPass(int seatNumber) {
    std::cout << "\n--- Boarding Pass ---\n";
    std::cout << "Seat Number: " << seatNumber << "\n";
    if (seatNumber >= 1 && seatNumber <= 5) {
        std::cout << "Class: First Class\n";
    } else {
        std::cout << "Class: Economy\n";
    }
    std::cout << "---------------------\n\n";
}
