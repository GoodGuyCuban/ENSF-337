// hydro.cpp
// ENSF 337 Fall 2021 Lab 8 Exercises C

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#include "list.h"
#include "hydro.h"

int main()
{
    FlowList list;
    DisplayHeader();
    readData(list);
    menu(list);
    return 0;
}

void DisplayHeader()
{
    cout << "Program: Flow Studies - Fall 2020" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: B02" << endl;
    cout << "Produced by: Marcos Perez" << endl;
    pressEnter();
}

void readData(FlowList& list)
{
    ifstream fin;
    fin.open("flow.txt");
    if (fin.fail()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    ListItem item;
    while (fin >> item.year >> item.flow) {
        list.insert(item);
    }
    fin.close();
}

void menu(FlowList& list)
{
    char choice;
    while (true) {
        cout << "Please select on the following operations" << endl;
        cout << "1. Display the list, and the average." << endl;
        cout << "2. Add data." << endl;
        cout << "3. Save data into the file" << endl;
        cout << "4. Remove data" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: \(1, 2, 3, 4, or 5\): ";
        cin >> choice;
        switch (choice) {
            case '1':
                display(list);
                break;
            case '2':
                addData(list);
                break;
            case '3':
                saveData(list);
                break;
            case '4':
                removeData(list);
                break;
            case '5':
                cout << "Program terminated successfully." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}


void display(FlowList& list)
{
    cout << "Year\tFlow \(in billions of cubic meters\)" << endl;
    cout << "----------------" << endl;
    list.reset();
    while (list.hasNext()) {
        ListItem item = list.next();
        cout << item.year << "\t" << item.flow << endl;
    }
    average(list);
    cin.ignore();
    pressEnter();
}

void addData(FlowList& list)
{
    ListItem item;
    cout << "Enter the year: ";
    cin >> item.year;
    cout << "Enter the flow: ";
    cin >> item.flow;
    
    list.reset();
    while (list.hasNext()) {
        ListItem temp = list.next();
        if (temp.year == item.year) {
            cout << "Error: duplicate data" << endl;
            cin.ignore();
            pressEnter();
            return;
        }
    }
    list.insert(item);
    cout << "Data added successfully." << endl;
    cin.ignore();
    pressEnter();
}

void removeData(FlowList& list)
{
    ListItem item;
    cout << "Enter the year: ";
    cin >> item.year;
    // check if data exists
    if (list.remove(item)) {
        cout << "Record was successfully removed." << endl;
    } else {
        cout << "Data does not exist." << endl;
    }
    cin.ignore();
    pressEnter();
}

void average(FlowList& list)
{
    double sum = 0;
    int count = 0;
    list.reset();
    while (list.hasNext()) {
        ListItem item = list.next();
        sum += item.flow;
        count++;
    }
    cout << "The annual average of the flow is: " << sum / count << " billions of cubic meter" << endl;
}

void saveData(FlowList& list)
{
    ofstream fout;
    fout.open("flow.txt");
    if (fout.fail()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    list.reset();
    while (list.hasNext()) {
        ListItem item = list.next();
        fout << item.year << "\t" << item.flow << endl;
    }
    fout.close();
    cout << "Data saved successfully." << endl;
    cin.ignore();
    pressEnter();
}

void pressEnter()
{
    cout << "\n<<< Press enter to continue >>>>\n";
    cin.get();
}

// Path: list.h