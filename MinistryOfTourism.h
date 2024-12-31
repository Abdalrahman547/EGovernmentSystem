#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsMinistry.h"
using namespace std;

class MinistryOfTourism : public clsMinistry
{
private:
    vector<string> TouristPlaces;

public:

    MinistryOfTourism () {}

    MinistryOfTourism(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
    {
        clsDepartment D1(MinistryName, "Tourism Services Office");

        vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);
    }

    void CheckTourismPlaces()
    {

        if (!TouristPlaces.empty())
        {
            for (string palace : TouristPlaces)
            {
                cout << palace;
                cout << "\n_________\n ";
            }
        }
        else
        {
            cout << "No places ): \n";
        }
    }

    void LoadTouristPlacesFromFile()
    {
        fstream MyFile("TouristPlaces.txt", ios::in);

        try
        {
            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    if (!Line.empty())
                    {
                        TouristPlaces.push_back(Line);
                    }
                }

                MyFile.close();
            }
        }
        catch (...)
        {
            cout << "\nError during oppening the file :(\n";
        }
    }

    void Reset()
    {
        TouristPlaces.clear();
    }

    void ShowMinistryIformation()
    {
       
        vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);

        cout << "\nMinistry Name: Ministry of " << _Name << endl;
        cout << "\nMinister Name: " << _MinsterName << endl;


        cout << "\nDepartments: ";

        for (auto D : vDepartments)
        {
            D.ShowDepartment();

            cout << "_____________\n";

        }

        cout << "\n____________________________________________________\n";

    }
};
