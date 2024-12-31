#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsTrip
{
    string _TripNumber;
    string _TrainNumber;
    string _ArrivalStation;
    string _TakeoffStation;
    double _Price;
    string _TripDay;
    string _ArrivalTime;
    string _TakeoffTime;


public:

    clsTrip(string TripNum, string TrainNum, string ArrivalSta, string TakeoffSta,string Tripday, string ArrivalTim, string TakeoffTim, double price)
    {
        _TripNumber = TripNum;
        _TrainNumber = TrainNum;
        _ArrivalStation = ArrivalSta;
        _TakeoffStation = TakeoffSta;
        _TripDay = Tripday;
        _ArrivalTime = ArrivalTim;
        _TakeoffTime = TakeoffTim;
        _Price = price;
    }

    static clsTrip ConvertLineToTripObject(string DataLine, string delim = "|-|")
    {
        vector<string> vTripData = clsString::Split(DataLine, delim);

        return clsTrip(vTripData[0], vTripData[1], vTripData[2],
            vTripData[3], vTripData[4], vTripData[5], vTripData[6], stod(vTripData[7]));

    }

    static vector<clsTrip> LoadTripsDataFromFile()
    {
        vector<clsTrip> vTrips;

        fstream MyFile;

        MyFile.open("Trips.txt", ios::in);

        try
        {
            if (MyFile.is_open())
            {
                string Line;

                while (getline(MyFile, Line))
                {
                    clsTrip T = ConvertLineToTripObject(Line);

                    vTrips.push_back(T);
                }

                MyFile.close();
            }

            return vTrips;
        }
        catch (...)
        {
            cout << "\nError during oppening the file :(\n";
        }

       
    }

    string getArrivalStation()
    {
        return _ArrivalStation;
    }

    void ShowTripDetails()
    {
        cout << "\n________________________________\n";
        cout << "Trip Number: " << _TripNumber << endl;
        cout << "Train Number: " << _TrainNumber << endl;
        cout << "Arrival Time: " << _ArrivalTime << endl;
        cout << "Takeoff Time: " << _TakeoffTime << endl;
        cout << "Price: " << _Price << endl;
        cout << "_________________________________\n";
    }

};

