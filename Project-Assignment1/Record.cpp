#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include "Record.h"

using namespace std;

// Input Details
void Record::AddRec()
{

    cout << "\nEnter  start Location    : ";
    cin.ignore();
    cin.getline(sLocation, 21);

    cout << "\nEnter start time [hh:mm] : ";
    cin >> sTime;
    cout << "\nEnter start Odometer (Km): ";
    cin >> sOdometer;
    cout << "\nEnter end Location    \t : ";
    cin.ignore();
    cin.getline(ELocation, 21);

    cout << "\nEnter  end time  [hh:mm] : ";
    cin >> ETime;
    cout << "\nEnter end Odometer (Km)  : ";
    cin >> EOdometer;
    cout << "\nEnter fuel(Litter) spent during the trip: ";
    cin >> fuel;
}

// show Details
void Record::ShowRec(int i)
{

    cout << "\n";
    cout << left << setw(5) << i << "| " << left << setw(17) << sLocation << "| " << left << setw(12)
         << sTime << "| " << left << setw(17) << sOdometer << "| " << left << setw(14) << ELocation
         << "| " << left << setw(10) << ETime << "| " << left << setw(14) << EOdometer << "| " << left << setw(10) << fuel;
}
