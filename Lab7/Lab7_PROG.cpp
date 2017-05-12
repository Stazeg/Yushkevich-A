#include "stdafx.h" //using C++/CLI
#include "Speciality.h"
#include "Students.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#using <System.dll>

using namespace System;
using namespace System::Diagnostics;
using namespace std;

void OpenFile(char *fileName, vector <Speciality> &specs)
{
	string name;
	int number, k;
	ifstream fin;

	setlocale(0, "ru-RU");
	fin.open(fileName);

	fin >> number;
	for (long i = 0; i < number; ++i)
	{
		fin >> name >> k;

		Speciality temp(name, k);
		specs.push_back(temp);
	}

	fin.close();
}

void Dialogs(vector <string> &d)
{
	int number;
	ifstream fin;

	fin.open("ru.txt");
	fin >> number;
	d.resize(number);
	for (int i = 0; i < number; ++i)
		getline(fin, d[i]);

	fin.close();
}

void Info(vector <string> &dialogs)
{
	cout << dialogs[1] << "\n";

	Process::Start("tutorial.txt");
	system("pause");
}

bool NewStudent(vector <Speciality> &specs)
{

	string name, info, spec;
	int CT1, CT2, CT3, sum;
	double avg;

	getline(cin, name);
	getline(cin, name);
	cin >> CT1 >> CT2 >> CT3 >> avg;
	cin >> spec;
	getline(cin, info);
	getline(cin, info);
	
	sum = CT1 + CT2 + CT3 + avg * 10;

	Student _new(name, sum, info, spec);

	for (int i = 0; i < specs.size(); ++i)
		if (specs[i].GetName() == spec)
		{
			return specs[i].Add(_new);
		}

	return false;
}

bool EraseStudent(vector <Speciality> &specs)
{
	string name;

	cin >> name;

	for (int i = 0; i < specs.size(); ++i)
		if (specs[i].Erase(name))
		{
			return true;
		}

	return false;
}

void Finish(vector <Speciality> &specs)
{
	for (int i = 0; i < specs.size(); ++i)
	{
		specs[i].Display();
	}
}

int main()
{
	vector <Speciality> specs;
	vector <string> dialogs;

	OpenFile("specialities.in", specs);
	Dialogs(dialogs);
	Info(dialogs);
	
	string input = "";
	while (input != "0")
	{
		cin >> input;

		if (input == "new")
		{
			cout << (NewStudent(specs) ? dialogs[2] : dialogs[3]) << "\n\n";
			continue;
		}

		if (input == "erase")
		{
			cout << (EraseStudent(specs) ? dialogs[4] : dialogs[7]) << "\n\n";
			continue;
		}

		if (input == "currentPoints")
		{
			cout << "\n" << dialogs[5] << ":\n";
			for (int i = 0; i < specs.size(); ++i)
				cout << " " << specs[i].GetName() << "    " << specs[i].GetPoints() << "\n\n";
			continue;
		}

		if (input == "help")
		{
			Info(dialogs);
			continue;
		}

		if (input == "results")
		{
			cout << dialogs[6] << "\n\n";
			Finish(specs);
			break;
		}

		cout << dialogs[8] << "\n\n";
	}

	system("pause");
    return 0;
}
