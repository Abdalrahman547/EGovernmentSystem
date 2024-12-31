#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsEmployee.h"
#include "clsForm.h"

using namespace std;

class clsDepartment
{
protected:

	string _Name;
	string _MinistryName;
	bool _MarkForDelete = false;

	vector<clsEmployee> _vEmployees;

	vector<clsForm> _vForms;

	static clsDepartment _ConvertLineToDepartmentObject(string DataLine, string delim = "|-|")
	{
		vector<string> vExamsData = clsString::Split(DataLine, delim);

		return clsDepartment(vExamsData[0], vExamsData[1]);
	}

	static string _ConvertDepartmentObjectToLine(clsDepartment D, string delim = "|-|")
	{
		string Line = "";

		Line += D.getMinistryName() + delim;
		Line += D.getDepartmentName();

		return Line;
	}

public:

	clsDepartment () {}

	clsDepartment(string MinistryName, string name)
	{
		_MinistryName = MinistryName;
		_Name = name;
	}

	string getDepartmentName() const
	{
		return _Name;
	}

	string getMinistryName()
	{
		return _MinistryName;
	}

	void RemoveEmployee(string EmployeeName)
	{
		for (auto& E : _vEmployees)
		{
			if (E.getFullName() == EmployeeName)
			{
				E.MarkforDeleted();
				break;
			}
		}

		clsEmployee::SaveEmployeesDataToFile(_vEmployees);
	}

	void DisplayForm(string FormID)
	{
		for (auto F : _vForms)
		{
			if (F.getFormID() == FormID)
			{
				F.ShowForm();
				break;
			}
		}
	}

	void RemoveForm(string FormID)
	{
		auto it = std::remove_if(_vForms.begin(), _vForms.end(), [&FormID](const clsForm& F)
		{
			return F.getFormID() == FormID;
		});

		if (it != _vForms.end())
		{
			_vForms.erase(it, _vForms.end());
		}

		clsForm::SaveFormsDataToFile(_vForms);
	}

	void ShowDepartment()
	{
		_vEmployees = clsEmployee::LoadEmployeesDataFromFile(_Name);

		cout << "\n\nDepartment Name: " << _Name << endl;

		if (_vEmployees.empty())
		{
			cout << "\aNo Eomployees in this department.\n";
			return;
		}


		cout << "\nEmployees: \n\n";

		cout << left << setw(30) << "Full Name" << " | " << setw(20) << "National ID" << endl;
		cout << string(53, '-') << endl;

		for (auto E : _vEmployees)
			cout << left << setw(30) << E.getFullName() << " | " << setw(20) << E.getNationalID() << endl;

			
	} 

	static vector<clsDepartment> LoadDepartmentsDataFromFile()
	{
		vector<clsDepartment> vDepartments;

		fstream MyFile("Departments.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsDepartment D = _ConvertLineToDepartmentObject(Line);

					vDepartments.push_back(D);
				}

				MyFile.close();
			}
			return vDepartments;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static vector<clsDepartment> LoadDepartmentsDataFromFile(string MinistryName)
	{
		vector<clsDepartment> vDepartments;

		fstream MyFile("Departments.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsDepartment D = _ConvertLineToDepartmentObject(Line);

					if (D.getMinistryName() == MinistryName)
						vDepartments.push_back(D);
				}

				MyFile.close();
			}
			return vDepartments;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static void SaveDepartmentsDataToFile(vector<clsDepartment> vDepartments)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Departments.txt", ios::out);

		try
		{
			if (MyFile.is_open())
			{
				for (auto D : vDepartments)
				{
					if (!D._MarkForDelete)
					{
						Line = _ConvertDepartmentObjectToLine(D);

						MyFile << Line << endl;
					}
				}

				MyFile.close();
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		

	}

	static void AddDepartmentToFile(string MinistryName, string DepartmentName)
	{
		fstream MyFile("Departments.txt", ios::out | ios::app);

		try
		{
			if (MyFile.is_open())
			{
				MyFile << MinistryName << "|-|" << DepartmentName << endl;
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	void MarkForDeleted()
	{
		_MarkForDelete = true;
	}
};

