#include <iostream>

class Record
{
    // Data Members
protected:
    char sLocation[20];
    char sTime[25];
    int sOdometer;
    char ELocation[20];
    char ETime[25];
    int EOdometer;
    int fuel;

    //  Member Function
public:
    // Record() {}
    Record() {}

    void AddRec();           // Input Data
    void ShowRec(int index); // Output Data

    int getsOdometer()
    {
        return (sOdometer);
    }
    int getEOdometer()
    {
        return (EOdometer);
    }
    int getfuel()
    {
        return (fuel);
    }

    ~Record() {}
};
