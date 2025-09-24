#include <iostream>
#include <iomanip>
#include "Time.h"

Time::Time(int h, int m, int s) {
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printStandard() const {
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    std::cout << displayHour << ":"
              << std::setw(2) << std::setfill('0') << minute << ":"
              << std::setw(2) << std::setfill('0') << second
              << (hour < 12 ? " AM" : " PM") << std::endl;
}

void Time::tick() {
    ++second;
    if (second == 60) {
        second = 0;
        ++minute;
        if (minute == 60) {
            minute = 0;
            ++hour;
            if (hour == 24) {
                hour = 0; // new day
            }
        }
    }
}
