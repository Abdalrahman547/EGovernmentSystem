#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
#include "clsEmployee.h"
using namespace std;


class clsRemoveEmployeeScreen : protected clsScreen
{

	static void _RemoveEmployee()
	{
		vector<clsEmployee> vEmployees;

		bool found = false;

		do
		{

			cout << "\nEnter Full Name of the Employee want to remove: ";
			string FullName;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, FullName);

			cout << "\nHis National ID: ";
			string NationalID;
			cin >> NationalID;

			cout << "\nHe works in which department? ";
			string Department;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, Department);

			vEmployees = clsEmployee::LoadEmployeesDataFromFile();

			if (vEmployees.empty())
			{
				cout << "\nNo Employee work on this department :(\a";
				return;
			}

			bool found = false;
			
			for (auto& E : vEmployees)
			{
				if (E.getFullName() == FullName && E.getNationalID() == NationalID)
				{
					E.MarkforDeleted();
					found = true;
					break;
				}
			}

			if (found)
			{
				cout << "\nAre you sure to remove this Employee? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;

				cout << "\nEmployee Removed Successfully :)\a\n";

				clsEmployee::SaveEmployeesDataToFile(vEmployees);
				return;

			}

			else
			{
				cout << "\nNo Employee for this Name or National ID :(\a";
				cout << "\n\nWant to try another one? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;
			}
					
		} while (!found);

	}


public:

	static void ShowRemoveEmployeeScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Remove Employee Screen");

		_RemoveEmployee();
	}

};

