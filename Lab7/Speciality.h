#pragma once
#include "Students.h"
#include <string>
#include <set>
#include <vector>
using namespace std;

class Speciality
{
public:
	Speciality(std::string name, int number);

	bool Add(Student &newStudent);

	bool Erase(string name);
	
	string GetName();

	int GetPoints();

	void Display();

private:

	string _name;
	int _points, _number;

	vector <Student> _queue;
};