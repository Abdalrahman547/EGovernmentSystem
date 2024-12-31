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
	string _Ministry;
	string _Department;

	bool _MarkForDelete = false;

	static clsEmployee _ConvertLineToEmployeeObject(string DataLine, string delim = "|-|")
	{
		vector<string> vEmployeeData = clsString::Split(DataLine, delim);

		return clsEmployee(vEmployeeData[0], vEmployeeData[1], vEmployeeData[2], vEmployeeData[3],
			stoi(vEmployeeData[4]), vEmployeeData[5], vEmployeeData[6], vEmployeeData[7], vEmployeeData[8]);

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
		Line += E.getPosition() + delim;
		Line += E.getMinistryName() + delim;
		Line += E.getDepartmentName();

		return Line;
	}


public:


	clsEmployee () {}

	clsEmployee(string name, string id, string phone, string adress, int age, string email, string pos, string Minstry, string dep)
		:clsPerson(name, id, phone, adress, age, email)
	{
		_Position = pos;
		_Ministry = Minstry;
		_Department = dep;
	}

	string getPosition()
	{
		return _Position;
	}

	string getDepartmentName()
	{
		return _Department;
	}

	string getMinistryName()
	{
		return _Ministry;
	}

	void MarkforDeleted()
	{
		_MarkForDelete = true;
	}

	static vector<clsEmployee> LoadEmployeesDataFromFile()
	{
		vector<clsEmployee> vEmployees;

		fstream MyFile;

		MyFile.open("Employees.txt", ios::in);

		try
		{
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
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static vector<clsEmployee> LoadEmployeesDataFromFile(string Department)
	{
		vector<clsEmployee> vEmployees;

		fstream MyFile;

		MyFile.open("Employees.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsEmployee E = _ConvertLineToEmployeeObject(Line);

					if (E.getDepartmentName() == Department)
						vEmployees.push_back(E);

				}

				MyFile.close();
			}

			return vEmployees;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static void SaveEmployeesDataToFile(vector<clsEmployee> vEmployees)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Employees.txt", ios::out);

		try
		{
			if (MyFile.is_open())
			{
				for (auto E : vEmployees)
				{
					if (!E._MarkForDelete)
					{
						Line = _ConvertEmployeeObjectToLine(E);

						MyFile << Line << endl;
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

	void AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Employees.txt", ios::out | ios::app);

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

	static bool EmployeeExists(clsEmployee Employee)
	{
		fstream MyFile;

		MyFile.open("Employees.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsEmployee E = _ConvertLineToEmployeeObject(Line);

					if (E.getNationalID() == Employee.getNationalID())
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

	void AddNew()
	{
		AddDataLineToFile(_ConvertEmployeeObjectToLine(*this));
	}

	friend istream& operator >> (istream& I, clsEmployee& E)
	{
		cout << "In what Ministry he will work in? ";
		cin >> E._Ministry;

		cout << "\nEnter Employee Full name: ";
		I.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(I, E._FullName);

		do
		{
			cout << "\nHis National ID: ";
			I >> E._NationalID;

		} while (E._NationalID.length() != 14);
		
		do
		{
			cout << "\nHis phone number: ";
			I >> E._PhoneNumber;
		} while (E._PhoneNumber.length() != 11);

		cout << "\nHis adress: ";
		I.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(I, E._Adress);

		cout << "\nHis Age: ";
		cin >> E._Age;

		cout << "\nHis email: ";
		I >> E._Email;

		cout << "\nHis Departments: ";
		I.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(I, E._Department);

		cout << "\nHis position: ";
		getline(I, E._Position);

		return I;
	}

};

