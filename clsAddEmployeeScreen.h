#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsEmployee.h"
#include "clsOwner.h"
using namespace std;


class clsAddEmployeeScreen : protected clsScreen
{

public:

	static void ShowAddEmployeeScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Add New Employee Screen");

		President.AddEmployeeToDepartment();

		

	}
};

