#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsOwner.h"
#include "clsInputValidate.h"
#include "clsAddEmployeeScreen.h"
#include "clsRemoveEmployeeScreen.h"
#include "clsAddMinstryScreen.h"
#include "clsRemoveExistingMinistryScreen.h"
#include "clsEditMinistryScreen.h"
#include "clsNumberOfCitizinesScreen.h"
#include "clsNumberOfMinstriesScreen.h"
#include "clsNumberOfEmployeesScreen.h"

using namespace std;

class clsOwnerMainMenuScreen: public clsScreen
{
	enum enOwnerOptions
	{
		enShowMinistries = 1, enAddNewMinistry = 2, enEditExistingMinistry = 3, enRemoveExistingMinistry = 4,
		enAddEmployeeToMinistry = 5, enRemoveEmployeeFromMinistry = 6, emAddFormToSpecificDeparment = 7,
		enRemoveFormFromSpecificDeparment = 8, enCountOfExistingMinistries = 9, enCountOfCitizensRegistered = 10,
	    enCountOfEmployeesRegistered = 11 ,enUpdateCurrancyPrices =12, enExit = 13
	};

	static short _ReadOwnerMainMenuOption()
	{
		short op;

		do
		{
			cout << "Choice option [1 to 13]: ";

			op = clsInputValidate::ReadShortNumber();

		} while (op < 1 || op > 13);

		return op;
	}

	static void _GoBackToOwnerMenuScren()
	{
		cout << "\n\n\nPress any key to go back to Main Menu...";

		system("pause>0");

		ShowOwnerMainMenuScreen();
	}

	static void _ShowMinistriesScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Show Ministries Screen");

		President.ShowMinistries();
	}

	static void _AddMinstryScreen()
	{
		clsAddMinstryScreen::ShowAddNewMinstryScreen();
	}

	static void _EditMinistryScreen()
	{
		clsEditMinistry::ShowEditMinstryScreen();
	}

	static void _RemoveExistingMinstry()
	{
		clsRemoveExistingMinistryScreen::ShowRemoveExistingMinistryScreen();
	}

	static void _AddEmployeeToMinistry()
	{
		clsAddEmployeeScreen::ShowAddEmployeeScreen();
	}

	static void _RemoveEmployeeScreen()
	{
		clsRemoveEmployeeScreen::ShowRemoveEmployeeScreen();
	}

	static void _AddFormToMinistry()
	{
		system("cls");

		_DrawOwnerScreenHeader("Add New Form Screen");

		clsForm::AddNewForm();
	}

	static void _RemoveFormFromMinistry()
	{
		system("cls");

		_DrawOwnerScreenHeader("Remove Form Screen");

		clsForm::Deleteform();
	}

	static void _CountOfExistingMinistries()
	{
		clsNumberOfMinstriesScreen::ShowNumberOfMinistriesScreen();
	}

	static void _CountOfCitizensRegistered()
	{
		clsNumberOfCitizinesScreen::ShowNumberOfCitizinesScreen();
	}

	static void _CountOfEmployeesRegistered()
	{
		clsNumberOfEmployeesScreen::ShowNumberOfEmployeesScreen();
	}

	static void _PerformEditOptions(enOwnerOptions OP)
	{
		switch (OP)
		{

		case clsOwnerMainMenuScreen::enShowMinistries:
			_ShowMinistriesScreen();
			_GoBackToOwnerMenuScren();
			break;
		
		case clsOwnerMainMenuScreen::enAddNewMinistry:
			_AddMinstryScreen();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enEditExistingMinistry:
			_EditMinistryScreen();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enRemoveExistingMinistry:
			_RemoveExistingMinstry();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enAddEmployeeToMinistry:
			_AddEmployeeToMinistry();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enRemoveEmployeeFromMinistry:
			_RemoveEmployeeScreen();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::emAddFormToSpecificDeparment:
			_AddFormToMinistry();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enRemoveFormFromSpecificDeparment:
			_RemoveFormFromMinistry();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enCountOfExistingMinistries:
			_CountOfExistingMinistries();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enCountOfCitizensRegistered:
			_CountOfCitizensRegistered();
			_GoBackToOwnerMenuScren();
			break;

		case clsOwnerMainMenuScreen::enCountOfEmployeesRegistered:
			_CountOfEmployeesRegistered();
			_GoBackToOwnerMenuScren();
			break;
			//------------------------------
		case clsOwnerMainMenuScreen::enUpdateCurrancyPrices:
			MinistryOfFinance::updateCurrencyFile();
			_GoBackToOwnerMenuScren();
			break;
			
		case clsOwnerMainMenuScreen::enExit:
		{
			system("cls");

			cout << "\n\nAre you sure you want to exit? (Y/N)? ";

			char ch;

			cin >> ch;

			if (tolower(ch) == 'y')
			{
				cout << '\a';
				exit(1);
			}

			ShowOwnerMainMenuScreen();

			break;
		}
	
		default:
			break;
		}
	}

public:

	static void ShowOwnerMainMenuScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Owner Main Menu Screen");

		cout << "\n[1] Show Ministries. \n";
		cout << "\n[2] Add New Ministry. \n";
		cout << "\n[3] Edit Existing Ministry. \n";
		cout << "\n[4] Remove Existing Ministry. \n";
		cout << "\n[5] Add Employee To Ministry. \n";
		cout << "\n[6] Remove Employee From Ministry. \n";
		cout << "\n[7] Add Form To Specific Deparment. \n";
		cout << "\n[8] Remove Form From Specific Deparment. \n";
		cout << "\n[9] Get Count Of Existing Ministries. \n";
		cout << "\n[10] Show Number of Citizens Registered In The System. \n";
		cout << "\n[11] Show Number of Employees Registered In The System. \n";
		cout << "\n[12] UpdateCurrancyPrices. \n";
		cout << "\n[13] Exit. \n\n";

		_PerformEditOptions((enOwnerOptions)_ReadOwnerMainMenuOption());
	}

};

