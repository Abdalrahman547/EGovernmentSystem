#pragma once
#include <iostream>
#include <vector>
#include "clsExam.h"
#include "clsMinistry.h"
#include "clsDepartment.h"
#include "clsString.h"
#include "clsInputValidate.h"
using namespace std;

class clsMinistryOfEducation : public clsMinistry
{
	vector<clsExam> _vExams;

	static string _ReadStagelExam()
	{
		cout << "Enter Stage Exam : ";

		string STName = clsInputValidate::ReadString();

		return clsString::LowerAllString(STName);
	}

public:

	clsMinistryOfEducation(string MinistryName, string MinisterName) : clsMinistry(MinistryName, MinisterName)
	{
		clsDepartment D1(MinistryName, "Primary School");
		clsDepartment D2(MinistryName, "Preparatory School");
		clsDepartment D3(MinistryName, "Secondary School");

	}

	static void searchForExam(string nationalID, string stage)
	{
		system("cls");
	
		bool found = false;
		vector<clsExam> exams = clsExam::LoadExamDataFromFile();
		fstream MyFile;

		MyFile.open("Exams.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;


				for (auto exam : exams)
				{
					if (exam.getStudentNationalID() == nationalID && exam.getExamStage() == stage)
					{
						found = true;
						exam.ShowExamDetails();

					}
				}
				cout << '\a';
			}

			if (!found)
			{
				cout << "\nSorry, no exams found for this student in the specified stage.\n";
			}
			MyFile.close();
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
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
