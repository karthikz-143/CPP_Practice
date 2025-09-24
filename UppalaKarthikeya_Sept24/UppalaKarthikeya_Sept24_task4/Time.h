#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

class Time {
private:
    int hour;   
    int minute; 
    int second; 

public:
    Time(int h = 0, int m = 0, int s = 0);

    // Set functions
    bool setHour(int);
    bool setMinute(int);
    bool setSecond(int);
    bool setTime(int, int, int);

    // Get functions
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const; // HH:MM:SS (24-hour)
    void printStandard() const;  // HH:MM:SS AM/PM
};

#endif
