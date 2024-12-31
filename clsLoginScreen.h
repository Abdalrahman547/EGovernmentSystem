#pragma once
#include <iostream>
#include "Global.h"
#include "clsCitizen.h"
#include "clsInputValidate.h"
#include "clsOwnerMainMenuScreen.h"
#include "clsFillFormScreen.h"
using namespace std;

class clsLoginScreen
{

	static short ReadOption()
	{
		short op;

		do
		{
			cout << "\nChoose what do you want? [1 to 3]: ";
			op = clsInputValidate::ReadShortNumber();

		} while (op < 1 || op > 3);

		return op;
	}

	enum enLoginOption { enLoginOwner = 1, enRegisterCitizen = 2, enLoginCitizen = 3 };

	static void OwnerLogin()
	{
		system("cls");

		string username, password;

		bool LoginFaild = false;

		cout << "\t\t\t\t     ___________________________________________";
		cout << "\n\n\t\t\t\t\t Owner Login Screen ";
		cout << "\n\t\t\t\t     ___________________________________________\n\n";

		do
		{
			cout << "Enter Username? ";
			cin.ignore(1, '\n');
			getline(cin, username);

			cout << "\nEnter Password? ";
			cin >> password;

			if (President.getFullName() == username && President.getPassword() == password)
				LoginFaild = true;

			if (!LoginFaild)
				cout << "\nInvalid Username/Password!\n\a";

		} while (!LoginFaild);


		clsOwnerMainMenuScreen::ShowOwnerMainMenuScreen();
	}

	static void CitizenLogin()
	{
		system("cls");

		vector<clsCitizen> vCitizines = clsCitizen::LoadCitizenDataFromFile();

		string username, password;

		bool LoginFaild = false;

		cout << "\t\t\t\t     ___________________________________________";
		cout << "\n\n\t\t\t\t\t Citizen Login Screen ";
		cout << "\n\t\t\t\t     ___________________________________________\n\n";

		do
		{

			cout << "Enter Username? ";
			cin.ignore(1, '\n');
			getline(cin, username);

			cout << "\nEnter Password? ";
			cin >> password;

			for (auto C : vCitizines)
			{
				if (C.getFullName() == username && C.getPassword() == password)
				{
					CurrentCitizen = C;
					LoginFaild = true;
					break;
				}

			}

			if (!LoginFaild)
				cout << "\nInvalid Username/Password!\n";


		} while (!LoginFaild);

		system("cls");

		clsFillFormScreen::ShowFillFormScreen();
	}

	static void CitizenRegister()
	{
		system("cls");

		cout << "\t\t\t\t     ___________________________________________";
		cout << "\n\n\t\t\t\t\t Citizen Register Screen ";
		cout << "\n\t\t\t\t     ___________________________________________\n\n";

		clsCitizen C;

		cin >> C;

		if (clsCitizen::CitizenExists(C))
		{
			cout << "\nYou already have an account :)\a";
			GoBackToLoginScreen();
		}

		C.AddNew();

		cout << "\nAccount registerd successfully :)\a";

		GoBackToLoginScreen();
	}

	static void GoBackToLoginScreen()
	{
		cout << "\nPress any key to go back to login screen...";
		system("pause>0");

		ShowLoginScreen();
	}

	static void PerformMainMenuOptions(enLoginOption OP)
	{
		switch (OP)
		{
		case clsLoginScreen::enLoginOwner:
			OwnerLogin();
			break;

		case clsLoginScreen::enRegisterCitizen:
			CitizenRegister();
			GoBackToLoginScreen();
			break;

		case clsLoginScreen::enLoginCitizen:
			CitizenLogin();
			break;

		default:
			break;
		}
	}


public:

	static void ShowLoginScreen()
	{
		system("cls");

		cout << "\t\t\t\t     ___________________________________________";
		cout << "\n\n\t\t\t\t\t\t Login Screen ";
		cout << "\n\t\t\t\t     ___________________________________________\n\n";

		cout << "\t\t\t\t\t[1] Login as Owner\n";
		cout << "\t\t\t\t\t[2] Register a Citizen\n";
		cout << "\t\t\t\t\t[3] Login as a Citizen\n";

		PerformMainMenuOptions((enLoginOption)ReadOption());
	}

};

