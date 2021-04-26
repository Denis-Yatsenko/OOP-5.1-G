//////////////////////////////////////////////////////////////////////////////
// Student.h
#pragma once
#include <string>
#include "Man.h"
//#pragma pack(push, 1)

using namespace std;

class Student
	: public Man
{
private:
	int course;
	//Man man;

public:
	int GetCourse() const { return course; }
	Man GetMan() const
	{
		Man man;
		man.SetName(this->GetName());
		man.SetAge(this->GetAge());
		man.SetGender(this->GetGender());
		man.SetWeight(this->GetWeight());
		return man;
	}

	void SetCourse(int course) { this->course = course; }
	void SetMan(Man man)
	{
		this->SetName(man.GetName());
		this->SetAge(man.GetAge());
		this->SetGender(man.GetGender());
		this->SetWeight(man.GetWeight());
		//this->man = man;
	}

	void Init(int course, Man man);
	string toString() const;
	void Display() const;
	void Read();

	void IncCourse() { this->course++; }

	Student(const int course = 0, const string name = "Studentka", const int age = 0, const char gender = 'F', const double weight = 0)
		throw(const char*, Exception, Bad_exception, bad_exception&, invalid_argument&);
	Student(const Student& s) { SetCourse(s.GetCourse()); SetMan(s.GetMan()); }

	Student& operator --();
	Student& operator ++();
	Student operator --(int);
	Student operator ++(int);

	friend ostream& operator <<(ostream& out, const Student& s);
	friend istream& operator >>(istream& in, Student& s) throw(const char*, bad_exception&);

	Student& operator =(const Student& s);

	operator string() const;

};
