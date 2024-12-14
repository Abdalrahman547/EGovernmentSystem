#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsstring.h"

using namespace std;
class clsEmployee : public clsPerson
{
	string _Position;

	static clsEmployee _ConvertLineToEmployeeObject(string DataLine, string delim = "|-|")
	{
		vector<string> vEmployeeData = clsString::Split(DataLine, delim);

		return clsEmployee(vEmployeeData[0], vEmployeeData[1], vEmployeeData[2],
			vEmployeeData[3], stoi(vEmployeeData[4]), vEmployeeData[5], vEmployeeData[6]);

	}

	static string _ConvertEmployeeObjectToLine(clsEmployee E, string delim = "|-|")
	{
		string Line = "";

		Line += E.getFullName() + delim;
		Line += E.getNationalID() + delim;
		Line += E.getPhoneNumber() + delim;
		Line += E.getAdress() + delim;
		Line += to_string(E.getAge()) + delim;
		Line += E.getEmail() + delim;
		Line += E.getPosition();

		return Line;
	}

	static vector<clsEmployee> _LoadEmployeesDataFromFile()
	{
		vector<clsEmployee> vEmployees;

		fstream MyFile;

		MyFile.open("Employees.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsEmployee E = _ConvertLineToEmployeeObject(Line);

				vEmployees.push_back(E);
			}

			MyFile.close();
		}

		return vEmployees;
	}

	static void _SaveClientsDataToFile(vector<clsEmployee> vEmployees)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Employees.txt", ios::out);

		if (MyFile.is_open())
		{
			for (auto E : vEmployees)
			{
				Line = _ConvertEmployeeObjectToLine(E);

				MyFile << Line << endl;
			}

			MyFile.close();
		}

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Employees.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertEmployeeObjectToLine(*this));
	}

public:

	clsEmployee(string name, string id, string phone, string adress, int age, string email, string pos)
		:clsPerson(name, id, phone, adress, age, email)
	{
		_Position = pos;
	}

	string getPosition()
	{
		return _Position;
	}
};

