#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
private:
    int month;   // 1-12
    int day;     // 1-31
    int year;    // >0
    int hour;    // 0-23
    int minute;  // 0-59
    int second;  // 0-59

    bool isLeapYear(int) const;
    int daysInMonth(int, int) const;

public:
    DateAndTime(int = 1, int = 1, int = 2000, int = 0, int = 0, int = 0);

    void setDate(int, int, int);
    void setTime(int, int, int);
    void printStandard() const;   
    void printUniversal() const;  
    void tick();                  
    void nextDay();               
};

#endif
