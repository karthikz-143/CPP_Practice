#include <iostream>
#include "HealthProfile.h"

// Constructor
HealthProfile::HealthProfile(std::string first, std::string last, std::string gen,
                             int month, int day, int year, double heightInches, double weightPounds)
    : firstName(first), lastName(last), gender(gen),
      birthMonth(month), birthDay(day), birthYear(year),
      height(heightInches), weight(weightPounds) {}

// Setters and Getters
void HealthProfile::setFirstName(std::string first) { firstName = first; }
std::string HealthProfile::getFirstName() const { return firstName; }

void HealthProfile::setLastName(std::string last) { lastName = last; }
std::string HealthProfile::getLastName() const { return lastName; }

void HealthProfile::setGender(std::string gen) { gender = gen; }
std::string HealthProfile::getGender() const { return gender; }

void HealthProfile::setBirthMonth(int month) { birthMonth = month; }
int HealthProfile::getBirthMonth() const { return birthMonth; }

void HealthProfile::setBirthDay(int day) { birthDay = day; }
int HealthProfile::getBirthDay() const { return birthDay; }

void HealthProfile::setBirthYear(int year) { birthYear = year; }
int HealthProfile::getBirthYear() const { return birthYear; }

void HealthProfile::setHeight(double heightInches) { height = heightInches; }
double HealthProfile::getHeight() const { return height; }

void HealthProfile::setWeight(double weightPounds) { weight = weightPounds; }
double HealthProfile::getWeight() const { return weight; }

// Calculate Age
int HealthProfile::getAge() const {
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

// Heart rate calculations
int HealthProfile::getMaximumHeartRate() const {
    int age = getAge();
    return 220 - age;
}

std::pair<int, int> HealthProfile::getTargetHeartRate() const {
    int maxHR = getMaximumHeartRate();
    int lower = static_cast<int>(maxHR * 0.50);
    int upper = static_cast<int>(maxHR * 0.85);
    return std::make_pair(lower, upper);
}

// BMI calculation
double HealthProfile::getBMI() const {
    return (weight * 703) / (height * height);
}
