#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsMinistry.h"
#include "clsScreen.h"
#include "clsOwner.h"
#include "clsInputValidate.h"
#include "clsOwnerMainMenuScreen.h"
using namespace std;


class clsEditMinistryInfoScreen : public clsScreen
{
	static void EditMinistryInformation()
	{
		string MinistryName, MinisterName;
		bool found = false;

		do
		{
			cout << "\nEnter Ministry Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, MinistryName);

			int index = President.SearchForMinistry(MinistryName);

			if (index != -1)
			{
				cout << "\nAre you sure you want to Edit information of this Ministry? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;

				string NewName;

				cout << "\nEnter New Ministry Name: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, NewName);

				cout << "\nEnter Minister Name: ";
				getline(cin, MinisterName);


				President.EditMinstryInformation(index, NewName, MinisterName);

				cout << "\nMinistry information updated successfully :)\a\n";

				found = true;
			}

			if (!found)
			{
				cout << "\nDo not found Ministry with this name.\n\n\a";

				char ch;
				cout << "Want to try another one? (Y/N)? ";
				cin >> ch;

				if (tolower(ch) == 'n')
					return;

			}


		} while (!found);
	}

public:

	static void ShowEditMinistryInformationScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Edit Ministry Information Screen");

		EditMinistryInformation();
	}
};

