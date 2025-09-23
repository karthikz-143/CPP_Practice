#include <iostream>
#include <cstdlib>
#include "Craps.h"


int rollDice() {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    return die1 + die2;
}

// Positive return = number of rolls until win
// Negative return = number of rolls until loss
int playGame() {
    int myPoint = 0;
    int rollCount = 1;

    int sumOfDice = rollDice();

    // First roll decisions
    switch (sumOfDice) {
        case 7:
        case 11:
            return rollCount; // win on first roll
        case 2:
        case 3:
        case 12:
            return -rollCount; // lose on first roll
        default:
            myPoint = sumOfDice;
            break;
    }

    // Continue rolling until win or loss
    while (true) {
        rollCount++;
        sumOfDice = rollDice();

        if (sumOfDice == myPoint) {
            return rollCount; // win
        } else if (sumOfDice == 7) {
            return -rollCount; // lose
        }
    }
}
