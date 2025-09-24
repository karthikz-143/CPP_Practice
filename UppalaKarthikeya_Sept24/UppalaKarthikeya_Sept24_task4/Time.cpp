#include "Time.h"

Time::Time(int h, int m, int s) {
    if (!setTime(h, m, s)) {  
        // If invalid, default to midnight
        hour = 0;
        minute = 0;
        second = 0;
    }
}

bool Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
        return true;
    }
    return false;
}

bool Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        minute = m;
        return true;
    }
    return false;
}

bool Time::setSecond(int s) {
    if (s >= 0 && s < 60) {
        second = s;
        return true;
    }
    return false;
}

bool Time::setTime(int h, int m, int s) {
    if (setHour(h) && setMinute(m) && setSecond(s)) {
        return true;
    }
    return false;
}

int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second;
}

void Time::printStandard() const {
    int displayHour = (hour % 12 == 0) ? 12 : hour % 12;
    std::cout << std::setfill('0') << std::setw(2) << displayHour << ":"
              << std::setw(2) << minute << ":"
              << std::setw(2) << second
              << (hour < 12 ? " AM" : " PM");
}
