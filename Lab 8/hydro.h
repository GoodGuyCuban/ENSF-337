// hydro.h
// ENSF 337 Fall 2021 Lab 8 Exercises C

#ifndef Hydro_H
#define Hydro_H

#include "list.h"
// main fucntion that uses the flowList class
int main();
// create DisplayHeader function
void DisplayHeader();
// create readData function
void readData(FlowList& list);
// create menu function
void menu(FlowList& list);
// displays year and flow, and shows the average by calling the average function
void display(FlowList& list);
// create addData function
void addData(FlowList& list);
// create removeData function
void removeData(FlowList& list);
// create average function
void average(FlowList& list);
// create saveData function
void saveData(FlowList& list);
// create pressEnter function
void pressEnter();

#endif /* Hydro_H */