#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>
#include <utility> 

class HeartRates {
public:
    // Constructor
    HeartRates(std::string first, std::string last, int month, int day, int year);

    // Set and get functions for firstName
    void setFirstName(std::string first);
    std::string getFirstName() const;

    // Set and get functions for lastName
    void setLastName(std::string last);
    std::string getLastName() const;

    // Set and get functions for birthMonth
    void setBirthMonth(int month);
    int getBirthMonth() const;

    // Set and get functions for birthDay
    void setBirthDay(int day);
    int getBirthDay() const;

    // Set and get functions for birthYear
    void setBirthYear(int year);
    int getBirthYear() const;

    // Function to calculate age 
    int getAge() const;

    // Function to calculate maximum heart rate
    int getMaximumHeartRate() const;

    // Function to calculate target heart rate range 
    std::pair<int, int> getTargetHeartRate() const;

private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
};

#endif
