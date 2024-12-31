#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
using namespace std;

class clsAddMinstryScreen : protected clsScreen
{
public:

	static void ShowAddNewMinstryScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Add New Ministry Screen");

		try
		{
			cin >> President;
		}
		catch (clsOwner::Exeption E)
		{
			E.ShowExeptionMsg();
			cout << '\a';
		}

	}
};

