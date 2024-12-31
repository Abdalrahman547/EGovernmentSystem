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


class clsRemoveExistingMinistryScreen : public clsScreen
{

	static void RemoveMinistry()
	{
		string MinistryName;
		bool found = false;

		do
		{
			cout << "\nEnter Ministry Name: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, MinistryName);

			int index = President.SearchForMinistry(MinistryName);

			if (index != -1)
			{
				cout << "\nAre you sure you want to delete this Ministry? (Y/N)? ";

				char ch;
				cin >> ch;

				if (tolower(ch) == 'n')
					return;

				President.DeleteMinistry(index);
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

	static void ShowRemoveExistingMinistryScreen()
	{
		system("cls");

		_DrawOwnerScreenHeader("Remove Ministry Screen");

		RemoveMinistry();

	}

};

