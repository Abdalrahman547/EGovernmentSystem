#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsPerson.h"
#include "clsstring.h"

class clsCitizen: public clsPerson
{
	string _Password;
	string _SocialSecurityNumber;
	string _VisaCardNumber;
	string _VisaCardPassword;
	double _ElectricityBill;

	static clsCitizen _ConvertLineToCitizenObject(string DataLine, string delim = "|-|")
	{
		vector<string> vCitizenData = clsString::Split(DataLine, delim);

		return clsCitizen(vCitizenData[0], vCitizenData[1], vCitizenData[2],
			vCitizenData[3], stoi(vCitizenData[4]), vCitizenData[5],
			vCitizenData[6], vCitizenData[7], vCitizenData[8],
			vCitizenData[9], stod(vCitizenData[10]));

	}

	static string _ConvertCitizenObjectToLine(clsCitizen E, string delim = "|-|")
	{
		string Line = "";

		Line += E.getFullName() + delim;
		Line += E.getNationalID() + delim;
		Line += E.getPhoneNumber() + delim;
		Line += E.getAdress() + delim;
		Line += to_string(E.getAge()) + delim;
		Line += E.getEmail() + delim;
		Line += E.getPassword() + delim;
		Line += E.getSocialSecurityNumber() + delim;
		Line += E.getVisaCardNumber() + delim;
		Line += E.getVisaCardPassword() + delim;
		Line += to_string(E.getElectricityBill());

		return Line;
	}

public:
	clsCitizen () {}

	clsCitizen(string name, string id, string phone, string adress, int age, string email,
		string pass, string socialNum, string visaNum, string visaPass, double elct)
		:clsPerson(name, id, phone, adress, age, email)
	{
		_Password = pass;
		_SocialSecurityNumber = socialNum;
		_VisaCardNumber = visaNum;
		_VisaCardPassword = visaPass;
		_ElectricityBill = elct;
	}

	string getPassword()
	{
		return _Password;
	}

	void setSocialSecurityNumber(string num)
	{
		_SocialSecurityNumber = num;
	}

	string getSocialSecurityNumber()
	{
		return _SocialSecurityNumber;
	}

	string getVisaCardNumber()
	{
		return _VisaCardNumber;
	}

	string getVisaCardPassword()
	{
		return _VisaCardPassword;
	}

	float getElectricityBill()
	{
		return _ElectricityBill;
	}

	void ShowInfo()
	{
		cout << "\n\t\t________________________________________\n";
		cout << "\t\t\tCitizens Information" << endl;
		cout << "\n\t\t________________________________________\n\n";

		cout << "\nName: " << clsPerson::getFullName();
		cout << "\nAge: " << clsPerson::getAge();
		cout << "\nAdress: " << clsPerson::getAdress();
		cout << "\nPhone: " << clsPerson::getPhoneNumber();
	}

	static vector<clsCitizen> LoadCitizenDataFromFile()
	{
		vector<clsCitizen> vCitizens;

		fstream MyFile;

		MyFile.open("Citizens.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsCitizen C = _ConvertLineToCitizenObject(Line);

					vCitizens.push_back(C);
				}

				MyFile.close();
			}

			return vCitizens;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}
		
	}

	static void SaveCitizenDataToFile(vector<clsCitizen> vCitizens)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Citizens.txt", ios::out);

		try
		{
			if (MyFile.is_open())
			{
				for (auto C : vCitizens)
				{
					Line = _ConvertCitizenObjectToLine(C);

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

	void AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Citizens.txt", ios::out | ios::app);

		try
		{
			if (MyFile.is_open())
			{

				MyFile << stDataLine << endl;

				MyFile.close();
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}


	}

	void AddNew()
	{
		AddDataLineToFile(_ConvertCitizenObjectToLine(*this));
	}

	static bool CitizenExists(clsCitizen Citizen)
	{
		fstream MyFile;

		MyFile.open("Citizens.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsCitizen C = _ConvertLineToCitizenObject(Line);

					if (Citizen.getNationalID() == C.getNationalID())
					{
						MyFile.close();

						return true;
					}

				}

				MyFile.close();

				return false;
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	friend istream& operator>>(istream& is, clsCitizen& C)
	{
		cout << "\nEnter your Full name: ";
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(is, C._FullName);

		do
		{
			cout << "\nEnter your National ID: ";
			is >> C._NationalID;
		} while (C._NationalID.length() != 14);

		do
		{
			cout << "\nEnter your phone number: ";
			is >> C._PhoneNumber;
		} while (C._PhoneNumber.length() != 11);

		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nEnter your adress: ";
		getline(is, C._Adress);

		cout << "\nEnter your age: ";
		is >> C._Age;

		cout << "\nEnter your email: ";
		is >> C._Email;

		cout << "\nEnter your password: ";
		is >> C._Password;

		cout << "\nEnter your social security number: ";
		is >> C._SocialSecurityNumber;

		cout << "\nEnter your visa card number: ";
		is >> C._VisaCardNumber;

		cout << "\nEnter your visa card password: ";
		is >> C._VisaCardPassword;

		cout << "\nEnter your Elictricity bill: ";
		is >> C._ElectricityBill;

		return is;
	}

};

