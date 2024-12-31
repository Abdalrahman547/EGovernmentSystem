#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class MinistryOfFinance: public clsMinistry
{
protected:
    vector<string> CuruncyPrices;

public:

    MinistryOfFinance () {}

    MinistryOfFinance(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
    {
        clsDepartment D1(MinistryName, "Currency Services Office");

        vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);

    }

    void CheckChangeRate() {
        system("cls");

        if (!CuruncyPrices.empty())
        {
            for (string price : CuruncyPrices)
            {
                cout << price << "\n_________\n";
            }
        }
        else
        {
            cout << "No currency prices available ): \n";
        }
        cout << '\a';
    }
    
    static void updateCurrencyFile()
    {
        string currency;
        cout << "\nEnter currency \n";
        cin >> currency;

        float buyValueToday;
        cout << "\nEnter buyValueToday \n";
        cin >> buyValueToday;

        float sellValueToday;
        cout << "\nEnter sellValueToday \n";
        cin >> sellValueToday;

        currency = currency + ':';

        fstream file("CurrencyPrices.txt", ios::in);

        if (!file.is_open())
        {
            cerr << "Failed to open the file for reading ): \n";
            return;
        }

        vector<string> fileLines;
        string line;


        while (getline(file, line))
        {
            stringstream ss(line);
            string currencyName, buyLabel, sellLabel;
            float buyValue, sellValue;


            ss >> currencyName >> buyLabel >> buyValue >> sellLabel >> sellValue;


            if (currencyName == currency)
            {
                buyValue = buyValueToday;
                sellValue = sellValueToday;
            }

            fileLines.push_back(currencyName + " Buy: " + to_string(buyValue) + " Sell: " + to_string(sellValue));
        }

        file.close();

        file.open("CurrencyPrices.txt", ios::out | ios::trunc);

        if (!file.is_open())
        {
            cerr << "Failed to open the file for writing ): \n";
            return;
        }


        for (auto& updatedLine : fileLines)
        {
            file << updatedLine << "\n";
        }

        file.close();
        cout << "Currency Price Updated successfully (: \n";
        cout << '\a';

    }

    void LoadCurrencyPricesFromFile()
    {
        fstream MyFile("CurrencyPrices.txt", ios::in);

        try
        {
            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    if (!Line.empty())
                    {
                        CuruncyPrices.push_back(Line);
                    }
                }

                MyFile.close();
            }
            else
            {
                cout << "Cannot open the file):\n";
            }
        }
        catch (...)
        {
            cout << "\nError during oppening the file :(\n";
        }

        
    }

    void Reset()
    {
        CuruncyPrices.clear();
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
