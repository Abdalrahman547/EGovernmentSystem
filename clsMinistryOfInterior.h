#pragma once
#include "clsMinistry.h"
#include "clsForm.h"
#include "clsCitizen.h"
using namespace std;

class clsMinistryOfInterior : public clsMinistry
{
	long long _GetRandomNumber(long long from, long long to)
	{
		long long RandNum = rand() % (to - from + 1) + from;
		return RandNum;
	}

public:
	clsMinistryOfInterior() {}

	clsMinistryOfInterior(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
	{

		clsDepartment D1(MinistryName, "Civil Status");

		vDepartments = clsDepartment::LoadDepartmentsDataFromFile(_Name);


	}

	void RenewSocialSecurityNumberCard(clsCitizen Citzen)
	{
		system("cls");

		vector<clsCitizen> vCitzens = clsCitizen::LoadCitizenDataFromFile();
		for (auto& C : vCitzens)
		{
			if (C.getNationalID() == Citzen.getNationalID())
			{
				C.setSocialSecurityNumber(to_string(_GetRandomNumber(1, 99999999)));
				cout << "Social Security Number updated successfully for National ID: " << C.getNationalID() << "\n";
				break;
			}
		}
	
		cout << '\a';
		clsCitizen::SaveCitizenDataToFile(vCitzens);
	
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

