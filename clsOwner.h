#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsMinistryOfTransportaion.h"
#include "clsMinistryOfInterior.h"
#include "clsMinistryOfEducation.h"
#include "MinistryOfFinance.h"
#include "MinistryOfTourism.h"
#include "MinistryOfHealthAndPopulation.h"
#include "clsMinistryOfElectricity.h"
#include "clsCitizen.h"
#include "clsEmployee.h"

using namespace std;

class clsOwner: public clsPerson
{

	string Password;

	clsMinistry* Ministries[25];

	vector<clsCitizen> vCititzens;

	int NumberOfMinistries;

	string PrimeMinister = "Dr. Mostafa Madpoly";

public:

	class Exeption
	{
		string msg;

	public:

		Exeption() {}

		Exeption(string Msg)
		{
			msg = Msg;
		}

		void ShowExeptionMsg()
		{
			cout << "\n" << msg << "\n";
		}

	};

	clsOwner () {}

	clsOwner(string name, string id, string phone, string adress, int age, string email, string Pass)
		:clsPerson(name, id, phone, adress, age, email)
	{
		Password = Pass;

		NumberOfMinistries = 7;

		vCititzens = clsCitizen::LoadCitizenDataFromFile();

		Ministries[0] = new clsMinistryOfTransportaion("Transportation", "Kamel Al-Wazir");
		Ministries[1] = new clsMinistryOfInterior("Interior", "Mohammed Tawfik");
		Ministries[2] = new clsMinistryOfEducation("Education", "Mohammed Abd Allatef");
		Ministries[3] = new MinistryOfFinance("Finance", "Ahmed kajok");
		Ministries[4] = new MinistryOfTourism("Tourism", "Sherif fathy");
		Ministries[5] = new clsMinistryOfElectricity("Electricity", "Mahmoud Esmat");
		Ministries[6] = new MinistryOfHealthAndPopulation("HealthAndPopulation", "Khalid Abd Alghfar");
	}

	string getPassword()
	{
		return Password;
	}

	clsMinistry getMinistry(int i)
	{
		return *Ministries[i];
	}

	int CountOfMinstry()
	{
		return NumberOfMinistries;
	}

	int CountOfCitzines()
	{
		return vCititzens.size();
	}

	void EditMinstryInformation(int i, string MinistryName, string MinisterName)
	{

		Ministries[i]->ChangeName(MinistryName);

		Ministries[i]->ChangeMinister(MinisterName);

	}

	void AddEmployeeToDepartment()
	{
		clsEmployee E;

		cin >> E;

		if (!clsEmployee::EmployeeExists(E))
		{
			E.AddNew();

			cout << "\nEmployee was added successfully :)\a";
		}

		else
			cout << "\nThis Employee is exsits allready :)\a";

	}

	int SearchForMinistry(string MinistryName)
	{
		for (int i = 0; i < NumberOfMinistries; i++)
			if (Ministries[i]->getName() == MinistryName)
				return i;

		return -1;
	}

	void DeleteMinistry(int i)
	{
		cout << "\n" << Ministries[i]->getName() << " deleted successfully :)\a\n";
		delete Ministries[i];

		--NumberOfMinistries;

	}

	friend istream& operator >>(istream& I, clsOwner& O)
	{
		string MinistryName, MinisterName;

		if (O.NumberOfMinistries > 25)
		{
			throw Exeption("We allready have is 25 Ministris.\n\nSo, According to The current Constitution, You Can not add any ministries");
			return I;
		}

		bool IsExists = false;

		do
		{
			if (IsExists)
			{
				cout << "\n\nMinistry is allready exists.\a\n\n";

				char ch;
				cout << "Want to add another one? (Y/N)? ";
				cin >> ch;

				if (tolower(ch) == 'n')
					return I;
			}


			cout << "\nEnter Ministry Name: ";
			I.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(I, MinistryName);

			cout << "\nEnter Minister Name: ";
			getline(I, MinisterName);

			for (int i = 0; i < O.NumberOfMinistries; i++)
			{
				if (O.Ministries[i]->getName() == MinistryName)
					IsExists = true;
			}

		} while (IsExists);
		

		O.Ministries[O.NumberOfMinistries++] = new clsMinistry(MinistryName, MinisterName);
		cout << "\n\nMinstry added succesfully :)\a";

		return I;
	}

	int IsMinistryExists(string MinistryName)
	{
		for (int i = 0; i < NumberOfMinistries; i++)
			if (Ministries[i]->getName() == MinistryName)
				return i;

		return -1;
	}

	void AddDepartmentInExsistingMinistry(string MinistryName, string DepartmentName)
	{
		int idx = IsMinistryExists(MinistryName);

		if (idx != -1)
		{
			Ministries[idx]->AddDepartment(DepartmentName);
			cout << "\nDepartment Added to Ministry of " << Ministries[idx]->getName() << " Successfully :)\a\n";
		}

		else
			cout << "\nNo Ministries with this name exists :(\a\n";
	}

	void ShowMinistries()
	{
		cout << "\nPrime Minister Name: " << PrimeMinister << "\n\n\n";

		for (int i = 0; i < NumberOfMinistries; i++)
			Ministries[i]->ShowMinistryIformation();
	}

	int getNumberOfMinistries() { return NumberOfMinistries; }
};

