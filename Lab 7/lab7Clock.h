//
//  lab7Clock.h
//  lab7
//

#ifndef lab7Clock_h
#define lab7Clock_h

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

class Clock {
public:

    Clock();
    Clock(int seconds);
    Clock(int h, int m, int s);
    
    void increment();
    void decrement();
    
    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);
    
    void add_seconds(int seconds);

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

private:
    int hour;
    int minute;
    int second;

    int hms_to_seconds(int h, int m, int s);
    void seconds_to_hms(int seconds, int& h, int& m, int& s);
};

#endif /* lab7Clock_h */