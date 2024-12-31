#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;


class clsVisaCard
{
    string _VisaCardNumber;
    string _VisaCardPassword;
    double _Balance;

    static clsVisaCard _ConvertLineToVisaCardObject(string DataLine, string delim = "|-|")
    {
        vector<string> vVisaCardsData = clsString::Split(DataLine, delim);

        return clsVisaCard(vVisaCardsData[0], vVisaCardsData[1], stod(vVisaCardsData[2]));
    }

	static string _ConvertVisaCardObjectToLine(clsVisaCard V, string delim = "|-|")
	{
		string Line = "";

		Line += V.getVisaCardNumber() + delim;
		Line += V.getVisaCardPassword() + delim;
		Line += to_string(V.getBalance());

		return Line;
	}


public:

	clsVisaCard() {}

	clsVisaCard(string num, string pass, double balance)
	{
		_VisaCardNumber = num;
		_VisaCardPassword = pass;
		_Balance = balance;
	}


	string getVisaCardNumber()
	{
		return _VisaCardNumber;
	}

	string getVisaCardPassword()
	{
		return _VisaCardPassword;
	}

	double getBalance()
	{
		return _Balance;
	}

	void setBalance(double balance)
	{
		_Balance = balance;
	}

	static vector<clsVisaCard> LoadVisaCardsDataFromFile()
	{
		vector<clsVisaCard> vVisaCards;

		fstream MyFile;

		try
		{
			MyFile.open("VisaCards.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsVisaCard V = _ConvertLineToVisaCardObject(Line);

					vVisaCards.push_back(V);
				}

				MyFile.close();
			}

			return vVisaCards;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static void SaveVisaCardsDataToFile(vector<clsVisaCard> vVisaCards)
	{
		fstream MyFile;
		string Line;

		MyFile.open("VisaCards.txt", ios::out);

		try
		{
			if (MyFile.is_open())
			{
				for (auto V : vVisaCards)
				{
					Line = _ConvertVisaCardObjectToLine(V);

					MyFile << Line << endl;
				}

				MyFile.close();
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		

	}

};

