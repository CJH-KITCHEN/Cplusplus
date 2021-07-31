#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Student
{
private:
	string sid;
	string name;
	int score;
public:
	Student() = default;
	~Student() = default;
	Student(const string& sid, const string& name, const int& score);
	bool operator<(const Student& std) const{
		return score < std.score;
	}
	bool operator>(const Student& std) const{
		return score > std.score;
	}
	bool operator==(const Student& std) const{
		return sid == std.sid;
	}
	bool operator==(const string& name) const {
		return this->name == name;
	}
	bool operator()(const Student& std) const {
		return sid == std.sid;
	}
	friend ostream& operator<<(ostream& out, const Student& std);

	string getId() const{
		return this->sid;
	}
	string getName() const {
		return this->name;
	}
	int getScore() const {
		return this->score;
	}
};

