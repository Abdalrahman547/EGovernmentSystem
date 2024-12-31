#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "clsDepartment.h"
#include "clsInputValidate.h"
using namespace std;

class clsMinistry
{
protected:

    string _Name;
    string _MinsterName;

    vector<clsDepartment> vDepartments;

public:
    clsMinistry() {}

    clsMinistry(string name, string MinsterName)
    {
        _Name = name;
        _MinsterName = MinsterName;
    }

    string getName()
    {
        return _Name;
    }

    string getMinisterName()
    {
        return _MinsterName;
    }

    friend vector<clsDepartment> getvDepartments(clsMinistry M)
    {
        return M.vDepartments;
    }

    void AddDepartment(string DepartmentName)
    {
        clsDepartment Department(_Name, DepartmentName);

        vDepartments.push_back(Department);
    }

    void ShowDepartments()
    {
        for (auto D : vDepartments)
            D.ShowDepartment();
    }

    void ChangeName(string NewName)
    {
        _Name = NewName;
    }

    void ChangeMinister(string NewMinisterName)
    {
        _MinsterName = NewMinisterName;
    }

    friend void EditMinistryInfo(clsMinistry M)
    {
        cout << "Enter New Minster Name: ";

        string NewMinsterName = clsInputValidate::ReadString();

        M._MinsterName = NewMinsterName;
    }

    virtual void ShowMinistryIformation()
    {
        cout << "\nMinistry Name: Ministry of " << _Name << endl;
        cout << "\nMinister Name: " << _MinsterName << endl;

        cout << "\nDepartments: ";

        cout << "\n____________________________________________________\n";
    
    }

};

