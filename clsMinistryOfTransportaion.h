#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsTrip.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsMinistry.h"
using namespace std;

class clsMinistryOfTransportaion : public clsMinistry
{
	static string _ReadArrivalStation()
	{
		cout << "Enter arrival station name: ";

		string STName = clsInputValidate::ReadString();

		return clsString::LowerAllString(STName);
	}

public:

	clsMinistryOfTransportaion(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
	{

		clsDepartment D1(MinistryName, "Ticket Reservation Office");

	}

	static void CheckTrainStation()
	{
		string Destnation = _ReadArrivalStation();

		fstream MyFile;

		MyFile.open("Trips.txt", ios::in);

		bool Found = false;

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsTrip T = clsTrip::ConvertLineToTripObject(Line);

				if (T.getArrivalStation() == Destnation)
				{
					Found = true;
					T.ShowTripDetails();
				}
			}

			if (!Found)
				cout << "\nSorry, there are not trips at this moment ):";


			 MyFile.close();
		}
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

