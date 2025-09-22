// main.cpp
// Program to test HeartRates class

#include <iostream>
#include "HeartRates.h"

int main() {
    std::string firstName, lastName;
    int month, day, year;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;

    // Create object
    HeartRates person(firstName, lastName, month, day, year);

    // Display details
    std::cout << "\nName: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/"
              << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;

    int age = person.getAge();
    std::cout << "Age: " << age << " years" << std::endl;

    int maxHR = 220 - age; 
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" << std::endl;

    std::pair<int, int> targetRange;
    targetRange.first = static_cast<int>(maxHR * 0.50);
    targetRange.second = static_cast<int>(maxHR * 0.85);
    std::cout << "Target Heart Rate Range: " << targetRange.first
              << " - " << targetRange.second << " bpm" << std::endl;

    return 0;
}
