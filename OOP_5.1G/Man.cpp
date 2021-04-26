
//////////////////////////////////////////////////////////////////////////////
// Man.cpp
#include "Man.h"
#include <iostream>
#include <sstream>

using namespace std;

void Man::Init(string name, int age, char gender, double weight)
{
	SetName(name);
	SetAge(age);
	SetGender(gender);
	SetWeight(weight);
}

string Man::toString() const
{
	stringstream sout;
	sout << "	Name : " << GetName() << endl
		<< "	Age : " << GetAge() << endl
		<< "	Gender : " << GetGender() << endl
		<< "	Weight : " << GetWeight()
		;
	return sout.str();
}

void Man::Display() const
{
	cout << toString();
}

void Man::Read()
{
	string name;
	int age;
	char gender;
	double weight;

	cout << endl;
	cout << "name = ? "; cin >> name;
	cout << "age = ? "; cin >> age;
	cout << "gender = ? "; cin >> gender;
	cout << "weight = ? "; cin >> weight;
	Init(name, age, gender, weight);
}

Man& Man::operator --() // ���������� ���������
{
	--age; // ������������ �������� ��'���
	return *this; // ��������� ������������� ��'���
}

Man& Man::operator ++() // ���������� ���������
{
	++age; // ������������ �������� ��'���
	return *this; // ��������� ������������� ��'���
}

Man Man::operator --(int) // ����������� ���������
{
	Man a(*this); // �������� ����
	age--; // ������������ �������� ��'���
	return a; // ��������� ����
}

Man Man::operator ++(int) // ����������� ���������
{
	Man a(*this); // �������� ����
	age++; // ������������ �������� ��'���
	return a; // ��������� ����
}

ostream& operator <<(ostream& out, const Man& m)
{
	return out << "	Name : " << m.GetName() << endl
		<< "	Age : " << m.GetAge() << endl
		<< "	Gender : " << m.GetGender() << endl
		<< "	Weight : " << m.GetWeight();
}

istream& operator >>(istream& in, Man& m) throw(const char*, bad_exception&)
{
	string name;
	int age;
	char gender;
	double weight;
	cout << "name = ? "; in >> name;
	m.SetName(name);
	cout << "age = ? "; in >> age;
	m.SetAge(age);
	cout << "gender = ? "; in >> gender;
	m.SetGender(gender);
	cout << "weight = ? "; in >> weight;
	m.SetWeight(weight);
	cout << endl;

	if (age < 0 && weight < 0)
	{
		cout << "By value : ";
		throw invalid_argument("invalid_agrument");
	}
	else if (age < 0)
	{
		cout << "By pointer : ";
		throw "exception";
	}
	else if (weight < 0)
	{
	
		cout << "By reference : ";
		throw bad_exception();
	}

	return in;
}

Man& Man::operator =(const Man& m)
{
	SetName(m.GetName());
	SetAge(m.GetAge());
	SetGender(m.GetGender());
	SetWeight(m.GetWeight());
	return *this;
}

Man::operator string() const
{
	stringstream sout;
	sout << toString();
	return sout.str();
}
