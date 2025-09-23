#include <iostream>
#include "UniqueNumbers.h"

int main() {
    const int MAX_NUMBERS = 20;
    int numbers[MAX_NUMBERS]; // array to hold unique numbers
    int uniqueCount = 0;      

    std::cout << "Enter 20 numbers between 10 and 100 :\n";

    for (int i = 0; i < MAX_NUMBERS; i++) {
        int input;
        std::cout << "Number " << (i + 1) << ": ";
        std::cin >> input;

        // Validate range
        if (input < 10 || input > 100) {
            std::cout << "Invalid! Enter a number between 10 and 100.\n";
            i--; 
            continue;
        }
        if (!isDuplicate(numbers, uniqueCount, input)) {
            numbers[uniqueCount] = input;
            uniqueCount++;
        } else {
            std::cout << "Duplicate ignored.\n";
        }
    }
    displayUnique(numbers, uniqueCount);

    return 0;
}
