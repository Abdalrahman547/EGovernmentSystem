#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

	static vector<clsCitizen> _LoadCitizenDataFromFile()
	{
		vector<clsCitizen> vCitizens;

		fstream MyFile;

		MyFile.open("Citizens.txt", ios::in);

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

	static void _SaveCitizenDataToFile(vector<clsCitizen> vCitizens)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Citizens.txt", ios::out);

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

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Citizens.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertCitizenObjectToLine(*this));
	}

public:

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

};

