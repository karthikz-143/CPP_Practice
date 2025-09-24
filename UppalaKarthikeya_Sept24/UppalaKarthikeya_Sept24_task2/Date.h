#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;  // 1-12
    int day;    // 1-31 (depending on month)
    int year;   // >0

    bool isLeapYear(int) const;      
    int daysInMonth(int, int) const; 

public:
    // constructor with defaults
    Date(int = 1, int = 1, int = 2000); 

    void setDate(int, int, int); // set and validate
    void printDate() const;      // print in mm/dd/yyyy format
    void nextDay();              
};

#endif
