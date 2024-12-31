#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
using namespace std;


class clsNumberOfCitizinesScreen : protected clsScreen
{

public:

	static void ShowNumberOfCitizinesScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Number of Citizins Screen");

		cout << "Number of citizins in country is: " << President.CountOfCitzines() << endl;
	}

};

