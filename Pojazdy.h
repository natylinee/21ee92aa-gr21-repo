#pragma once
#include <iostream>
using namespace std;

class Vehicle {
private:
	
	string type = "BRAK";
	string brand = "BRAK";
	int year=0;
public:
	Vehicle()
	{
		string type = "BRAK";
		string brand = "BRAK";
		int year = 0;
	}
	Vehicle(string type, string brand, int year)
	{
		this->type = type;
		this->brand = brand;
		this->year = year;
	}
	friend bool operator<(Vehicle vehicle1, Vehicle vehicle2)
	{
		return vehicle1.year < vehicle2.year;
	}
	friend bool operator>(Vehicle vehicle1, Vehicle vehicle2)
	{
		return vehicle1.year > vehicle2.year;
	}
	friend ostream& operator<<(ostream& out, Vehicle vehicle)
	{
		out << vehicle.type << vehicle.brand << vehicle.year;
		return out;
	}
	friend istream& operator >>(istream& in, Vehicle vehicle)
	{
		in >> vehicle.type >> vehicle.brand >> vehicle.year;
		return in;
	}
	friend bool operator !=(Vehicle vehicle1, Vehicle vehicle2)
	{
		if (vehicle1.brand != vehicle2.brand || vehicle1.type != vehicle2.type || vehicle1.year != vehicle2.year)
			return true;
	}
};
