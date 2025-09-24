#include <iostream>
#include <iomanip>
#include "DateAndTime.h"

DateAndTime::DateAndTime(int m, int d, int y, int h, int min, int s) {
    setDate(m, d, y);
    setTime(h, min, s);
}

bool DateAndTime::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int DateAndTime::daysInMonth(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(y) ? 29 : 28;
        default: return 31;
    }
}

void DateAndTime::setDate(int m, int d, int y) {
    year = (y > 0) ? y : 2000;
    month = (m >= 1 && m <= 12) ? m : 1;
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

void DateAndTime::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void DateAndTime::printStandard() const {
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::cout << month << "/" << day << "/" << year << "  "
              << displayHour << ":"
              << std::setw(2) << std::setfill('0') << minute << ":"
              << std::setw(2) << std::setfill('0') << second
              << (hour < 12 ? " AM" : " PM") << std::endl;
}

void DateAndTime::printUniversal() const {
    std::cout << month << "/" << day << "/" << year << "  "
              << std::setw(2) << std::setfill('0') << hour << ":"
              << std::setw(2) << std::setfill('0') << minute << ":"
              << std::setw(2) << std::setfill('0') << second
              << std::endl;
}

void DateAndTime::tick() {
    ++second;
    if (second == 60) {
        second = 0;
        ++minute;
        if (minute == 60) {
            minute = 0;
            ++hour;
            if (hour == 24) {
                hour = 0;
                nextDay();
            }
        }
    }
}

void DateAndTime::nextDay() {
    ++day;
    if (day > daysInMonth(month, year)) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}
