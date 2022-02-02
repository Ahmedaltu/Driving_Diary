#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <bits/stdc++.h>

#include "Record.h"
#include "Func.h"
#define BIN_FIE "Recoreds.bin"

using namespace std;

int main()
{
    Record rec;
    std::vector<Record> Rv; // vector of classes objects

    int choice;
    intro();
    while (1)
    {
        cout << "\n\n\t***** Main menu *****\n";
        cout << "1. Initialize (clear all records)\n";
        cout << "2. Save trip data to file\n";
        cout << "3. Add New Record\n";
        cout << "4. Read All Records\n";
        cout << "5. Delete trip by index\n";
        cout << "6. Calculate average fuel consumption\n";
        cout << "7. Exit\n";
        cout << "Enter you choice[1-7]: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        { // New Record
            ofstream file(BIN_FIE);
            cout << "\n\tCleared all records !!" << endl;
            break;
        }
        case 2:
        { // save Record to file
            try
            {
                ofstream file;
                file.open(BIN_FIE, ios::out | ios::app);
                for (auto i : Rv)
                {
                    file.write((char *)&i, sizeof(i)); // storing data into file
                }

                cout << "\n\tSaved!!!!!!\n";
                file.close();
            }
            catch (exception &e)
            {
                cout << "--> Standard exception: " << e.what() << endl;
            }
            Rv.clear();
            break;
        }
        case 3:
        { // New Record

            rec.AddRec(); // get data from user
            Rv.push_back(rec);
            break;
        }

        case 4:
        { // Display All Records
            ifstream file;
            file.open(BIN_FIE);

            cout << "\n\nAll Trips in the diary\n";
            decorate();
            int index = 1;
            while (file)
            {
                file.read((char *)&rec, sizeof(rec)); // reading data from file
                if (!file.eof())
                    rec.ShowRec(index); // displaying data on screen
                index++;
            }
            file.clear();
            file.close();
            break;
        }

        case 5:
        { // Delete  Records
            fstream file, file1;
            int h = 1;
            file.open(BIN_FIE);
            cout << "Enter inedx of trip you want to delete: ";
            int ind;
            cin >> ind;

            file1.open("temp.bin", ios::in | ios::out | ios::binary | ios::app | ios::ate);
            while (file.read((char *)&rec, sizeof(rec)))
            {

                if (ind != h)
                {
                    file1.write((char *)&rec, sizeof(rec)); // storing data into file
                }
                else
                {
                    cout << "\n\tFound!!!!!!\n";
                    decorate();
                    rec.ShowRec(ind);

                    cout << "\n\n\tDeleted!!!!!!\n";
                }
                h++;
            }
            if (ind > h)
            {
                cout << "\n\n\tError: Can't find the trip!!!!!!\n";
            }
            file.clear();
            file.close();
            file1.close();
            remove(BIN_FIE);
            rename("temp.bin", BIN_FIE);
            remove("temp.bin");

            break;
        }
        case 6:
        { // Calculate average fuel consumption
            fstream file;
            file.open(BIN_FIE);
            int Tfuel = 0;
            int Tdist = 0;
            while (file.read((char *)&rec, sizeof(rec)))
            {
                Tfuel = Tfuel + rec.getfuel();
                Tdist = Tdist + (rec.getEOdometer() - rec.getsOdometer());
            }
            cout << "\n\tTotal fuel: " << Tfuel << " L";
            cout << "\n\tTotal distance: " << Tdist << " Km";
            float ave = (float)Tdist / Tfuel;
            cout << "\n\tThe average fuel consumption : " << ave << " Km/L";
            file.clear();
            file.close();

            break;
        }

        case 7:
        {
            cout << "\n\tExiting !!!!!!!!\n";
            exit(0);
        }
        default:
        {
            cout << "\n\tInvalid option\n";
        }
        }
    }
}