#include <iostream>
#include "Date.h"

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

bool Date::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int Date::daysInMonth(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(y) ? 29 : 28;
        default: return 31; 
    }
}

void Date::setDate(int m, int d, int y) {
    // validate year
    year = (y > 0) ? y : 2000;

    // validate month
    month = (m >= 1 && m <= 12) ? m : 1;

    // validate day
    int maxDay = daysInMonth(month, year);
    day = (d >= 1 && d <= maxDay) ? d : 1;
}

void Date::printDate() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}
