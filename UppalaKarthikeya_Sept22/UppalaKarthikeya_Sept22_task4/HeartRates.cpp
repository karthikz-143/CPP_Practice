#include <iostream>
#include "HeartRates.h"

// Constructor
HeartRates::HeartRates(std::string first, std::string last, int month, int day, int year)
    : firstName(first), lastName(last), birthMonth(month), birthDay(day), birthYear(year) {}

// Setters and getters
void HeartRates::setFirstName(std::string first) { firstName = first; }
std::string HeartRates::getFirstName() const { return firstName; }

void HeartRates::setLastName(std::string last) { lastName = last; }
std::string HeartRates::getLastName() const { return lastName; }

void HeartRates::setBirthMonth(int month) { birthMonth = month; }
int HeartRates::getBirthMonth() const { return birthMonth; }

void HeartRates::setBirthDay(int day) { birthDay = day; }
int HeartRates::getBirthDay() const { return birthDay; }

void HeartRates::setBirthYear(int year) { birthYear = year; }
int HeartRates::getBirthYear() const { return birthYear; }

// Function to calculate age
int HeartRates::getAge() const {
    int currentMonth, currentDay, currentYear;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--; 
    }
    return age;
}

// Function to calculate maximum heart rate
int HeartRates::getMaximumHeartRate() const {
    int age = getAge();
    return 220 - age;
}

// Function to calculate target heart rate range
std::pair<int, int> HeartRates::getTargetHeartRate() const {
    int maxHR = getMaximumHeartRate();
    int lower = static_cast<int>(maxHR * 0.50);
    int upper = static_cast<int>(maxHR * 0.85);
    return std::make_pair(lower, upper);
}
