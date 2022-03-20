#pragma once
#include <iostream>
using namespace std;
class Person
{
public:
	string pesel;
	string name, surname, gender;

	Person()
	{
		pesel = "0";
		name = "BRAK";
		surname = "BRAK";
		gender = "BRAK";
	}
	Person(string pesel, string name, string surname, string gender)
	{
		this->pesel = pesel;
		this->name = name;
		this->surname = surname;
		this->gender = gender;
	}
	friend bool operator<(Person person1, Person person2)
	{
		return person1.surname < person2.surname;
	}
	friend bool operator>(Person person1, Person person2)
	{
		return person1.surname > person2.surname;
	}
	friend ostream& operator<<(ostream& out, Person& person)
	{
		out << person.pesel << " " << person.name << " " << person.surname << " " << person.gender;
		return out;
	}
	friend istream& operator >>(istream& in, Person& person)
	{
		in >> person.pesel >> person.name >> person.surname >> person.gender;
		return in;
	}
	friend bool operator !=(Person person1, Person person2)
	{
		if (person1.pesel != person2.pesel || person1.name != person2.name || person1.surname != person2.surname || person1.gender != person2.gender)
			return true;
		return false;
	}
};
