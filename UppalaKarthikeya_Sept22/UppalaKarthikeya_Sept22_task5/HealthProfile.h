#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

#include <string>
#include <utility> 

class HealthProfile {
public:
    // Constructor
    HealthProfile(std::string first, std::string last, std::string gen,
                  int month, int day, int year, double heightInches, double weightPounds);

    // Setters and Getters
    void setFirstName(std::string first);
    std::string getFirstName() const;

    void setLastName(std::string last);
    std::string getLastName() const;

    void setGender(std::string gen);
    std::string getGender() const;

    void setBirthMonth(int month);
    int getBirthMonth() const;

    void setBirthDay(int day);
    int getBirthDay() const;

    void setBirthYear(int year);
    int getBirthYear() const;

    void setHeight(double heightInches);
    double getHeight() const;

    void setWeight(double weightPounds);
    double getWeight() const;

    int getAge() const;
    int getMaximumHeartRate() const;
    std::pair<int, int> getTargetHeartRate() const;

    // BMI calculation
    double getBMI() const;

private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthMonth;
    int birthDay;
    int birthYear;
    double height;
    double weight; 
};

#endif
