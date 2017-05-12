#include "stdafx.h"
#include "Students.h"

Student::Student(std::string name, int points, std::string info, std::string speciality) : _name(name), _info(info), _points(points)
{
	_speciality = speciality;
}

bool Student::operator==(Student &A)
{
	if (this->_name == A.GetName())
		return true;
	else
		return false;
}

int Student::GetPoints()
{
	return _points;
}

std::string Student::GetName()
{
	return _name;
}
