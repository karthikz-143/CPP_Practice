#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;   
    int minute; 
    int second; 

public:
    // constructor
    Time(int = 0, int = 0, int = 0); 
    // set hour, minute, second
    void setTime(int, int, int);     
    void printStandard() const;      
    void tick();                     
};
#endif
