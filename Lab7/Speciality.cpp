#include "stdafx.h"
#include "Speciality.h"
#include <algorithm>
#include <string>
#include <iostream>

Speciality::Speciality(string name, int number) : _number(number), _name(name)
{
	_points = 0;
}


bool Speciality::Add(Student &newStudent)
{
	if (_queue.size() < _number)
	{
		_queue.push_back(newStudent);
		_points = max(_points, newStudent.GetPoints());
		return true;
	}

	if (newStudent.GetPoints() <= _points)
		return false;

	for (long i = 0; i < _queue.size(); ++i)
		if (_queue[i].GetPoints() == _points)
		{
			_queue[i] = newStudent;
			_points = newStudent.GetPoints();
		}
}


bool Speciality::Erase(string name)
{
	bool isExict = false;

	for (auto i = _queue.begin(); i != _queue.end(); ++i)
		if ((i->GetName()) == name)
		{
			_queue.erase(i);
			isExict = true;
		}

	_points = 0;
	for (int i = 0; i < _queue.size(); ++i)
		_points = max(_points, _queue[i].GetPoints());

	return isExict;
}

string Speciality::GetName()
{
	return _name;
}

int Speciality::GetPoints()
{
	return _points;
}

void Speciality::Display()
{
	std::cout << _name << " (" << _points << ") :\n";
	for (int i = 0; i < _queue.size(); ++i)
	{
		cout << " " << _queue[i].GetName() << "\n";
	}
}
