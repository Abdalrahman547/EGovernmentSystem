#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
using namespace std;


class clsNumberOfEmployeesScreen : protected clsScreen
{
public:

	static void ShowNumberOfEmployeesScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Number of Employees Screen");

		int NumOfEmployees = 0;

		fstream MyFile;

		MyFile.open("Employees.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				++NumOfEmployees;
			}

			MyFile.close();
		}

		cout << "Number of Employees in country is: " << NumOfEmployees << endl;
	}

};

