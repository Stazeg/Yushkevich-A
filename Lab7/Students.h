#pragma once
#include <string>

class Student
{
public:
	Student(std::string name, int points, std::string info, std::string speciality);

	bool operator ==(Student &A);

	int GetPoints();

	std::string GetName();

private:
	std::string _name, _info, _speciality;
	int _points;

};