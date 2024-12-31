#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "BloodBank.h"
using namespace std;

class MinistryOfHealthAndPopulation: public clsMinistry
{
private:
    vector<BloodBank> BloodBanks;

public:

    MinistryOfHealthAndPopulation () {}

    MinistryOfHealthAndPopulation(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
    {
        clsDepartment D1(MinistryName, "Blood Service Center");

        vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);
    }

    void SearchForBlood(Blood bloodData)
    {
        for (auto BloodBank : BloodBanks)
        {
            if (BloodBank.SearchForBloodd(bloodData))
            {
                
                return;
            }
        }
        cout << "Sorry Blood not found (: \n";
        return;
    }

    void addBloodBank(BloodBank bank)
    {
        BloodBanks.push_back(bank);
    }

    BloodBank ConvertLineToBloodBank(string Line)
    {
        vector<string> BankData = SplitString(Line);

        BloodBank bank;
        if (BankData.size() == 4)
        {
            bank.setNameOfBank(BankData[0]);
            bank.setLocationOfBank(BankData[1]);
            Blood blood(BankData[2], stoi(BankData[3]));
            bank.addBlood(blood);
        }

        return bank;
    }

    void LoadBloodBanksDataFromFile()
    {
        fstream MyFile("bloodbanks.txt", ios::in);

        try
        {
            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    BloodBank bank = ConvertLineToBloodBank(Line);
                    addBloodBank(bank);
                }

                MyFile.close();
            }
        }
        catch (...)
        {
            cout << "\nError during oppening the file :(\n";
        }

       
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
