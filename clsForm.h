#pragma once
#include <iostream>
using namespace std;

class clsForm
{
protected:
	string _FormID;
	string _MinistryName;
	string _FormName;

	string _DepartmentName;

	bool _MarkForDelete = false;

	static clsForm _ConvertLineToFormObject(string DataLine, string delim = "|-|")
	{
		vector<string> vFormData = clsString::Split(DataLine, delim);

		if (vFormData.size() < 4) {
			throw runtime_error("Invalid data format in file ):");
		}
		return clsForm(vFormData[0], vFormData[1], vFormData[2], vFormData[3]);

	}

	static string _ConvertFormObjectToLine(clsForm F, string delim = "|-|")
	{
		string Line = "";

		Line += F.getFormID() + delim;
		Line += F.getMinistryName() + delim;
		Line += F.getFormName() + delim;
		Line += F.getDepartmentName();

		return Line;
	}


public:

	clsForm() {}

	clsForm(string id, string MName, string FName,string DepartmentName)
	{
		_FormID = id;
		_MinistryName = MName;
		_FormName = FName;
		_DepartmentName = DepartmentName;
	}

	void MarkForDeleted()
	{
		_MarkForDelete = true;
	}

	string getFormName()
	{
		return _FormName;
	}

	string getMinistryName()
	{
		return _MinistryName;
	}

	string getFormID() const
	{
		return _FormID;
	}

	string getDepartmentName()
	{
		return _DepartmentName;
	}

	static vector<clsForm> LoadFormsDataFromFile()
	{
		vector<clsForm> vForms;

		fstream MyFile;

		MyFile.open("Forms.txt", ios::in);

		try
		{
			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsForm E = _ConvertLineToFormObject(Line);

					vForms.push_back(E);
				}

				MyFile.close();
			}

			return vForms;
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		
	}

	static void SaveFormsDataToFile(vector<clsForm> vForms)
	{
		fstream MyFile;
		string Line;

		MyFile.open("Forms.txt", ios::out);

		try
		{
			if (MyFile.is_open())
			{
				for (auto F : vForms)
				{
					if (!F._MarkForDelete)
					{
						Line = _ConvertFormObjectToLine(F);

						MyFile << Line << "\n";
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

	void AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Forms.txt", ios::out | ios::app);

		try
		{
			if (MyFile.is_open())
			{
				MyFile << stDataLine << "\n";
				MyFile.close();
			}
		}
		catch (...)
		{
			cout << "\nError during oppening the file :(\n";
		}

		

	}
	
	void AddNew()
	{
		AddDataLineToFile(_ConvertFormObjectToLine(*this));
	}

	void ShowForm()
	{
		cout << "Form Name: " << _FormName << "\n";
		cout << "Form ID: " << _FormID << "\n";
		cout << "Ministry Name: " << _MinistryName << "\n";
		cout << "Department Name: " << _DepartmentName << "\n";
	}
	//-------------------------------------------------------------------------------
	static void AddNewForm() {
		string id, ministryName, formName, DepartmentName;
		cout << "Enter Form ID: ";          cin >> id;
		cin.ignore();
		cout << "Enter Ministry Name: ";    getline(cin, ministryName);
		cout << "Enter Form Name: ";       getline(cin, formName);
		cout << "Enter Department Name: "; getline(cin, DepartmentName);

		
		clsForm newForm(id, ministryName, formName, DepartmentName);
		vector<clsForm> vForms = clsForm::LoadFormsDataFromFile();
		vForms.push_back(newForm);
		clsForm::SaveFormsDataToFile(vForms);
		cout << "Form added successfully (:\n";
	}

	static void Deleteform() {
		string DepartmentName, id;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	   cout << "Enter Department Name: ";
		getline(cin, DepartmentName); // Just show (:

		cout << "Enter Form ID: ";
		getline(cin, id);

		vector<clsForm> vForms = clsForm::LoadFormsDataFromFile();
		bool found = 0;
		for(auto& Form : vForms){
			if (Form.getFormID() == id) {
				Form.MarkForDeleted();
				//vForms.erase(vForms.begin() + i);
				found = 1;
				break;
			}
		}
		if (found) {
			clsForm::SaveFormsDataToFile(vForms);
			cout << "Form with ID: " << id <<" ,In Department: " << DepartmentName << " deleted successfully (:\n";
		}
		else {
			cout << "Form with ID: " << id << " not found ):\n";
		}
	}
	//-------------------------------------------------------------------------------

};

