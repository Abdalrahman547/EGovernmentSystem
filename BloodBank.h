
#include <iostream>
#include <vector>
#include <string >
#include <fstream>
#include "Blood.h"

using namespace std;
vector<string> SplitString(string S1, string delim = "|-|")
{
    size_t pos = 0;
    string word;
    vector<string> vString;

    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos);
        if (!word.empty())
            vString.push_back(word);
        S1.erase(0, pos + delim.length());
    }
    if (!S1.empty())
        vString.push_back(S1);

    return vString;
}

class BloodBank
{
private:
    vector<Blood> Bloods;
    string LocationOfBank;
    string NameOfBank;


public:
    void addBlood(Blood b)
    {
        Bloods.push_back(b);
    }
    
    string getNameOfBank()
    {
        return NameOfBank;
    }
    
    string getLocationOfBank()
    {
        return LocationOfBank;
    }
    
    BloodBank() {}
    
    void setNameOfBank(string name)
    {
        NameOfBank = name;
    }
    
    void setLocationOfBank(string loc)
    {
        LocationOfBank = loc;
    }

    bool SearchForBloodd(Blood BloodN)
    {
        for (auto &Blood : Bloods)
        {
            int countbloodbags = Blood.getCountOfBloodBag();
            if (Blood.getType() == BloodN.getType() && countbloodbags >= BloodN.getCountOfBloodBag())
            {
                string NameOfBank = getNameOfBank();
                string LocationOfBank = getLocationOfBank();
                cout << "Bank Name: " << NameOfBank << "\n";
                cout << "Bank Location: " << LocationOfBank << "\n";
                updateBloodFile(Blood, BloodN.getCountOfBloodBag());
                return 1;
            }
            else if (Blood.getType() == BloodN.getType() && countbloodbags < BloodN.getCountOfBloodBag())
            {
                cout << (countbloodbags != 0 ? "Sorry quntity of BloodBags not Enough, Only Exist: " + to_string(countbloodbags) + " Blood Bag\n" : "Sorry, Blood bags of this type are not available ): \n");
                return 1;
            }
        }
        return 0;
    }
    
    void updateBloodFile(Blood &updatedBlood, int minus)
    {
        fstream file("bloodbanks.txt", ios::in);

        if (!file.is_open())
        {
            cerr << "Failed to open the blood data file ): \n";
            return;
        }

        vector<string> fileLines;
        string line;
        bool isUpdated = false;

        while (getline(file, line))
        {
            vector<string> parts = SplitString(line, "|-|");

            if (parts.size() >= 4)
            {
                string BN = parts[0];
                string BL = parts[1];
                string BT = parts[2];
                int Bc = stoi(parts[3]);
                if (BT == updatedBlood.getType())
                {
                    // cerr << "Initial: " << Bc << "\n";
                    Bc -= minus;
                    // cerr << "Updated: " << Bc << "\n";

                    line = BN + "|-|" + BL + "|-|" + BT + "|-|" + to_string(Bc);
                    isUpdated = true;
                }
            }

            fileLines.push_back(line);
        }
        file.close();

        file.open("bloodbanks.txt", ios::out | ios::trunc);
        if (!file.is_open())
        {
            cerr << "Failed to write blood data  infile ): \n";
            return;
        }

        for (auto &updatedLine : fileLines)
        {
            file << updatedLine << "\n";
        }

        file.close();

        for (auto &blood : Bloods)
        {
            if (blood.getType() == updatedBlood.getType())
            {
               // blood.decreaseCount(minus);
                break;
            }
        }
    }
};