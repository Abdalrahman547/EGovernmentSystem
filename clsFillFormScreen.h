#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "MinistryOfHealthAndPopulation.h"
#include "MinistryOfTourism.h"
#include "clsMinistryOfTransportaion.h"
#include "MinistryOfFinance.h"
#include "clsMinistryOfInterior.h"
#include "clsCitizen.h"
#include "clsMinistryOfEducation.h"
#include "Global.h"
#include "clsVisaCard.h"
using namespace std;

class clsFillFormScreen : protected clsScreen
{
	enum enFormOption
	{
		enRenewSocialSecurityCard = 1,
		enCheckLastPrimaryExam = 2,
		enCheckLastSecondaryExam = 3,
		enCheckLastPreparatoryExam = 4,
		enViewCurrencyPrices = 5,
		enCheckTrainSchedual = 6,
		enCheckElectricitBill = 7,
		enSearchForBloodBags = 8,
		enViewTouristPlaces = 9,
		enExit = 10
	};

	static short ReadFormoption()
	{
		int op;

		do
		{
			cout << "Choice option [1 to 10]: ";

			op = clsInputValidate::ReadIntNumber();

		} while (op < 1 || op > 10);

		return op;
	}

	static void GoBackToFillFormScreen()
	{
		cout << "\nPress any key to go back to fill form screen...";
		system("pause>0");

		ShowFillFormScreen();
	}

	static void ShowFormsList() {
		vector<clsForm> vForms = clsForm::LoadFormsDataFromFile();

		if (vForms.empty()) {
			cout << "No forms available.\n";
		}
		else {
			cout << "Available Forms:\n";
			for ( auto& form : vForms) {
				form.ShowForm();
				cout << "------------------------\n";
			}
		}
		ShowFillFormScreen();
		GoBackToFillFormScreen();
	}

	static void PerformFormOptions(enFormOption OP)
	{
		string bloodType;
		int quantity;
		Blood boodX("", 0);
		clsMinistryOfInterior ministryInterior;

		switch (OP)
		{
		case clsFillFormScreen::enRenewSocialSecurityCard:
		
			ministryInterior.RenewSocialSecurityNumberCard(CurrentCitizen); 
			GoBackToFillFormScreen();
		
			break;

		case clsFillFormScreen::enCheckLastPrimaryExam:
			clsMinistryOfEducation::searchForExam(CurrentCitizen.getNationalID(), "Primary");
			GoBackToFillFormScreen();
			break;

		case clsFillFormScreen::enCheckLastSecondaryExam:
			clsMinistryOfEducation::searchForExam(CurrentCitizen.getNationalID(), "Secondary");
			GoBackToFillFormScreen();
			break;

		case clsFillFormScreen::enCheckLastPreparatoryExam:
			clsMinistryOfEducation::searchForExam(CurrentCitizen.getNationalID(), "Preparatory");
			GoBackToFillFormScreen();
			break;

		case clsFillFormScreen::enViewCurrencyPrices:
		{
			MinistryOfFinance ministryFinance;
			ministryFinance.LoadCurrencyPricesFromFile();
			ministryFinance.CheckChangeRate();
			GoBackToFillFormScreen();
		}
			break;

		case clsFillFormScreen::enCheckTrainSchedual:

			clsMinistryOfTransportaion::CheckTrainStation();
			GoBackToFillFormScreen();
			break;

		case clsFillFormScreen::enCheckElectricitBill:
		{
			system("cls");
		
			vector<clsVisaCard> vVisaCards = clsVisaCard::LoadVisaCardsDataFromFile();
			bool isUpdat = false;

			for (auto& V : vVisaCards)
			{
				double oldBalance = V.getBalance();
				if (V.getVisaCardNumber() == CurrentCitizen.getVisaCardNumber())
				{
					V.setBalance(V.getBalance() - CurrentCitizen.getElectricityBill());
					isUpdat = true;

					cout << "\nElectricity bill of " << CurrentCitizen.getElectricityBill()
						<< " has been deducted from your balance.\n";
					cout << "Old Balance: " << oldBalance << "\n";
					cout << "New Balance: " << V.getBalance() << "\n";
				}
			
			}
			if (isUpdat)
			{
				clsVisaCard::SaveVisaCardsDataToFile(vVisaCards);
				cout << "Operation completed successfully (:\n";
			}
			else
			{
				cout << "\nNo matching Visa Card found for the current citizen ):\n";
			}
			cout << '\a';
			GoBackToFillFormScreen();
		}

			break;

		case clsFillFormScreen::enSearchForBloodBags:
		{
			system("cls");
	
			MinistryOfHealthAndPopulation ministryHealth;
			ministryHealth.LoadBloodBanksDataFromFile();
			cout << "Enter Blood Type: ";
			cin >> bloodType;
			cout << "Enter Quantity: ";
			cin >> quantity;
			boodX = Blood(bloodType, quantity);
			ministryHealth.SearchForBlood(boodX);
			cout << '\a';
			GoBackToFillFormScreen();
		}
			break;

		case clsFillFormScreen::enViewTouristPlaces:
		{
			system("cls");
		
			MinistryOfTourism ministryTourism;
			ministryTourism.LoadTouristPlacesFromFile();
			ministryTourism.CheckTourismPlaces();
			cout << '\a';
			GoBackToFillFormScreen();
			break;
		}

		case clsFillFormScreen::enExit:
		{
			system("cls");
			cout << "\n\nAre you sure you want to exit? (Y/N)? ";
			char ch;
			cin >> ch;

			if (tolower(ch) == 'y')
			{
				cout << '\a';
				exit(1);
			}

			GoBackToFillFormScreen();

			break;
		}

		default:
			break;
		}
	}
	
public:

	static void ShowFillFormScreen()
	{
		system("cls");

		_DrawCitizenScreenHeader("Fill Form Screen");

		cout << "\n[1] Renew Social Security Card (Interior Ministry)\n";
		cout << "\n[2] Check Last Primary Exam (Education Ministry)\n";
		cout << "\n[3] Check Last Secondary Exam (Education Ministry)\n";
		cout << "\n[4] Check Last Preparatory Exam (Education Ministry)\n";
		cout << "\n[5] View Currency Prices (Finance Ministry)\n";
		cout << "\n[6] Check Train Schedule (Transportation Ministry)\n";
		cout << "\n[7] Check Electricity Bill (Electricity Ministry)\n";
		cout << "\n[8] Search for Blood Bags  (HealthAndPopulation Ministry)\n";
		cout << "\n[9] View Tourist Places (Tourism Ministry)\n";
		cout << "\n[10] Exit\n\n";

		PerformFormOptions((enFormOption)ReadFormoption());
	}

};
