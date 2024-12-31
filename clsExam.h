#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsstring.h"
#include "Global.h"

class clsExam
{
    string _StudentNationalID;
    string _ExamName;
    int _ExamYear;
    double _MaxMark;
    double _CurrentMark;
    string _ExaminerName;
    string _ExamStage;

    static clsExam _ConvertLineToExamObject(string DataLine, string delim = "|-|")
    {
        vector<string> vExamsData = clsString::Split(DataLine, delim);

        return clsExam(vExamsData[0], vExamsData[1], stoi(vExamsData[2]),
                       stod(vExamsData[3]), stod(vExamsData[4]), vExamsData[5], vExamsData[6]);
    }

public:
    clsExam(string StudentID, string Ename, int year, double maxMark, double currentMark, string ExaminerName, string stage)
    {
        _StudentNationalID = StudentID;
        _ExamName = Ename;
        _ExamYear = year;
        _MaxMark = maxMark;
        _CurrentMark = currentMark;
        _ExaminerName = ExaminerName;
        _ExamStage = stage;
    }

    string getExamName()
    {
        return _ExamName;
    }

    int getExamYear()
    {
        return _ExamYear;
    }

    double getMaxMark()
    {
        return _MaxMark;
    }

    double getCurrentMark()
    {
        return _CurrentMark;
    }

    string getExaminerName()
    {
        return _ExaminerName;
    }

    string getStudentNationalID()
    {
        return _StudentNationalID;
    }

    string getExamStage() { 
        return _ExamStage; 
    }

    void ShowExamDetails()
    {
        cout << "\n________________________________\n";
        cout << "Exam Stage: " << _ExamStage << "\n";
        cout << "Exam Name: " << _ExamName << "\n";
        cout << "Year: " << _ExamYear << "\n";
        cout << "Max Mark: " << _MaxMark << "\n";
        cout << "Current Mark: " << _CurrentMark << "\n";
        cout << "Examiner Name: " << _ExaminerName << "\n";
        cout << "Exam Stage: " << _ExamStage << "\n";
        cout << "_________________________________\n";
    }

    static vector<clsExam> LoadExamDataFromFile()
    {
        vector<clsExam> vExams;

        fstream MyFile("Exams.txt", ios::in);

        try
        {
            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsExam E = _ConvertLineToExamObject(Line);

                    vExams.push_back(E);
                }

                MyFile.close();
            }
            return vExams;
        }
        catch (...)
        {
            cout << "\nError during oppening the file :(\n";
        }

       
    }
};
