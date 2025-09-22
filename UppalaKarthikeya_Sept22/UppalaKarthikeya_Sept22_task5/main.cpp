#include <iostream>
#include "HealthProfile.h"

int main() {
    std::string firstName, lastName, gender;
    int month, day, year;
    double height, weight;

    // Get user input
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> day;
    std::cout << "Enter birth year: ";
    std::cin >> year;
    std::cout << "Enter height (in inches): ";
    std::cin >> height;
    std::cout << "Enter weight (in pounds): ";
    std::cin >> weight;

    // Create HealthProfile object
    HealthProfile person(firstName, lastName, gender, month, day, year, height, weight);

    // Display user details
    std::cout << "\n--- Health Profile ---" << std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Gender: " << person.getGender() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/"
              << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;
    std::cout << "Height: " << person.getHeight() << " inches" << std::endl;
    std::cout << "Weight: " << person.getWeight() << " pounds" << std::endl;

    // Calculations
    int age = person.getAge();
    std::cout << "Age: " << age << " years" << std::endl;

    double bmi = person.getBMI();
    std::cout << "BMI: " << bmi << std::endl;

    int maxHR = 220 - age;
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm" << std::endl;

    std::pair<int, int> targetRange;
    targetRange.first = static_cast<int>(maxHR * 0.50);
    targetRange.second = static_cast<int>(maxHR * 0.85);
    std::cout << "Target Heart Rate Range: " << targetRange.first
              << " - " << targetRange.second << " bpm" << std::endl;

    // BMI chart
    std::cout << "\n--- BMI VALUES ---" << std::endl;
    std::cout << "Underweight: less than 18.5" << std::endl;
    std::cout << "Normal:      18.5 - 24.9" << std::endl;
    std::cout << "Overweight:  25 - 29.9" << std::endl;
    std::cout << "Obese:       30 or greater" << std::endl;

    return 0;
}
