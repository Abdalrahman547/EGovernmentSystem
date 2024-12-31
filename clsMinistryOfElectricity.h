#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsMinistry.h"
using namespace std;


class clsMinistryOfElectricity : public clsMinistry
{

public:

	clsMinistryOfElectricity(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
	{
		clsDepartment D1(MinistryName, "Electricity Billing Services");

	}


	void ShowMinistryIformation()
	{
		vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);

		cout << "\nMinistry Name: Ministry of " << _Name << endl;
		cout << "\nMinister Name: " << _MinsterName << endl;


		cout << "\nDepartments: ";

		for (auto D : vDepartments)
		{
			D.ShowDepartment();

			cout << "_____________\n";

		}

		cout << "\n____________________________________________________\n";

	}

};

