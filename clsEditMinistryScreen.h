#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
#include "clsInputValidate.h"
#include "clsOwnerMainMenuScreen.h"
#include "clsEditMinistryInfoScreen.h"
#include "Global.h"
using namespace std;


class clsEditMinistry : protected clsScreen
{
	enum enEditOption
	{
		enEditInfo = 1, enAddDepartment = 2, enRemoveDepartment = 3
	};

	static short _ReadEditption()
	{
		short op;

		do
		{
			cout << "Choice option [1 to 3]: ";

			op = clsInputValidate::ReadShortNumber();

		} while (op < 1 || op > 3);

		return op;
	}

	static void _EditMinstryInfo()
	{
		clsEditMinistryInfoScreen::ShowEditMinistryInformationScreen();
		
	}

	static void _AddDepartment()
	{
		system("cls");

		_DrawOwnerScreenHeader("Add New Department Screen");

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nEnter Ministry Name: ";
		string MinistryName;
		getline(cin, MinistryName);

		cout << "\nEnter Department Name: ";
		string DepartmentName;
		getline(cin, DepartmentName);

		President.AddDepartmentInExsistingMinistry(MinistryName, DepartmentName);

		clsDepartment::AddDepartmentToFile(MinistryName, DepartmentName);

	}

	static void _RemoveDepartment()
	{
		system("cls");

		_DrawOwnerScreenHeader("Remove Department Screen");


		vector<clsDepartment> vDepartments;

		bool found = false;

		do
		{

			string MinistryName;
			cout << "\nEnter Ministry Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, MinistryName);

			cout << "\nEnter Department Name: ";
			string DepartmentName;
			getline(cin, DepartmentName);

			vDepartments = clsDepartment::LoadDepartmentsDataFromFile();

			if (vDepartments.empty())
			{
				cout << "\nNo Departments in this ministry :(\a";
				return;
			}

			bool found = false;

			for (auto& D : vDepartments)
			{
				if (D.getDepartmentName() == DepartmentName)
				{
					D.MarkForDeleted();
					found = true;
					break;
				}
			}

			if (found)
			{
				cout << "\nAre you sure to remove this Department? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;

				cout << "\nDepartment Removed Successfully :)\a\n";

				clsDepartment::SaveDepartmentsDataToFile(vDepartments);
				return;

			}

			else
			{
				cout << "\nNo Department for this Name :(\a";
				cout << "\n\nWant to try another one? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;
			}

		} while (!found);

		
	}

	static void _PerformEditOptions(enEditOption OP)
	{
		switch (OP)
		{
		case clsEditMinistry::enEditInfo:
			_EditMinstryInfo();
			break;

		case clsEditMinistry::enAddDepartment:
			_AddDepartment();
			break;

		case clsEditMinistry::enRemoveDepartment:
			_RemoveDepartment();
			break;

		default:
			break;
		}
	}


public:

	static void ShowEditMinstryScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Edit Minstry Informaton Screen");

		cout << "\n\t\t[1] Edit Ministry Information: \n";
		cout << "\n\t\t[2] Add Department To Ministry: \n";
		cout << "\n\t\t[3] Remove Department From Ministry: \n\n";

		_PerformEditOptions((enEditOption)_ReadEditption());
	}

};

