//
//   Lab7Clock.cpp
//   Lab 7
//
#include "lab7Clock.h"

//default constructor
Clock::Clock() {
    hour = 0;
    minute = 0;
    second = 0;
}
//second constructor
Clock::Clock(int seconds) {
    if (seconds < 0) {
        hour = 0;
        minute = 0;
        second = 0;
    }
    else {
        if (seconds > 86400) {
            seconds = seconds % 86400;
        }
        seconds_to_hms(seconds, hour, minute, second);
    }
}
//third constructor
Clock::Clock(int h, int m, int s) {
    if (h < 0 || m < 0 || s < 0 || h > 23 || m > 59 || s > 59) {
        hour = 0;
        minute = 0;
        second = 0;
    }
    else {
        hour = h;
        minute = m;
        second = s;
    }
}
//set hour function
void Clock::set_hour(int h) {
    if (h < 0 || h > 23) {
        return;
    }
    else {
        hour = h;
    }
}
//set minute function
void Clock::set_minute(int m) {
    if (m < 0 || m > 59) {
        return;
    }
    else {
        minute = m;
    }
}
//set second function
void Clock::set_second(int s) {
    if (s < 0 || s > 59) {
        return;
    }
    else {
        second = s;
    }
}

//helper functions
//hms to seconds
int Clock::hms_to_seconds(int h, int m, int s) {
    return (h * 3600) + (m * 60) + s;
}
//seconds to hms
void Clock::seconds_to_hms(int seconds, int& h, int& m, int& s) {
    h = seconds / 3600;
    m = (seconds % 3600) / 60;
    s = (seconds % 3600) % 60;
}

//increment function
void Clock::increment() {
    int seconds = hms_to_seconds(hour, minute, second);
    seconds++;
    if (seconds > 86399) {
        seconds = 0;
    }
    seconds_to_hms(seconds, hour, minute, second);
}
//decrement function
void Clock::decrement() {
    int seconds = hms_to_seconds(hour, minute, second);
    seconds--;
    if (seconds < 0) {
        seconds = 86399;
    }
    seconds_to_hms(seconds, hour, minute, second);
}
//add seconds function
void Clock::add_seconds(int s) {
    if (s < 0) {
        return;
    }
    int seconds = hms_to_seconds(hour, minute, second);
    seconds += s;
    if (seconds > 86399) {
        seconds = seconds % 86400;
    }
    seconds_to_hms(seconds, hour, minute, second);
}
//get hour function
int Clock::get_hour() const{
    return hour;
}
//get minute function
int Clock::get_minute() const{
    return minute;
}
//get second function
int Clock::get_second() const{
    return second;
}
