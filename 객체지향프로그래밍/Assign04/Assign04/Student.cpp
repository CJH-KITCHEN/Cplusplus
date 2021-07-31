#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
Student::Student():Student("noname", 0)
{
}

Student::~Student()
{
}

Student::Student(const string& name, const int& score)
{
	this->name = name;
	this->score = score;

}

string Student::getName() const
{
	return this->name;
}

int Student::getScore() const
{
	return this->score;
}

bool Student::operator==(const Student& student)
{
	return (this->name==student.getName())&& (this->score == student.getScore());
}

ostream& operator<<(ostream& out, Student& student)
{
	out << student.getName()<< " " << student.getScore() << endl;
	return out;
}
