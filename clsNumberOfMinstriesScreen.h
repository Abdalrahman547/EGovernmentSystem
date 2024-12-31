#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
using namespace std;

class clsNumberOfMinstriesScreen : protected clsScreen
{

public:

	static void ShowNumberOfMinistriesScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Number of Ministries Screen");

		cout << "Number of Ministries in country is: " << President.CountOfMinstry() << endl;
	}

};

