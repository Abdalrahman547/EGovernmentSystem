#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
protected:
	string _FullName;
	string _NationalID;
	string _PhoneNumber;
	string _Adress;
	int _Age;
	string _Email;

public:

	clsPerson() {}

	clsPerson(string name, string id, string phone, string adress, int age, string email)
	{
		_FullName = name;
		_NationalID = id;
		_PhoneNumber = phone;
		_Adress = adress;
		_Age = age;
		_Email = email;
	}

	string getFullName()
	{
		return _FullName;
	}

	string getNationalID()
	{
		return _NationalID;
	}

	string getPhoneNumber()
	{
		return _PhoneNumber;
	}

	string getAdress()
	{
		return _Adress;
	}

	int getAge()
	{
		return _Age;
	}

	string getEmail()
	{
		return _Email;
	}
};

