#pragma once
#include<iostream>
#include<iomanip>
#include"Global.h"
#include"clsDate.h"
using namespace std;


class clsScreen
{
protected:

    static void _DrawOwnerScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t     ___________________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t     ___________________________________________\n\n";
        cout << "\n\t\t\t\t\tThe Excellency the President: " << President.getFullName() << "\n";
        cout << "\t\t\t\t\tNational ID: " << President.getNationalID() << "\n";
        cout << "\t\t\t\t\tAge : " << President.getAge() << "\n";
        cout << "\t\t\t\t\tData/Time: " << clsDate::GetSystemDateTimeString() << "\n\n";
    }

    static void _DrawCitizenScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t     ___________________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t     ___________________________________________\n\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentCitizen.getFullName() << "\n";
        cout << "\t\t\t\t\tNational ID: " << CurrentCitizen.getNationalID() << "\n";
        cout << "\t\t\t\t\tData/Time: " << clsDate::GetSystemDateTimeString() << "\n\n";
    }

};


