#pragma once;

#include<iostream>
#include<string>
#pragma warning (disable : 4996)
using namespace std;

class Product
{
protected:
	string name;
	float cost;
	float weight;
	int theNumber;

public:
	Product() {}

	friend ostream& operator << (ostream& os, Product& pr)
	{
		os << "������������: " << pr.getName() << endl <<
			"���� ������: " << pr.getPrice() << endl <<
			"��� ������: " << pr.getWeight() << endl <<
			"���������� ������: " << pr.getTheNumber() << endl;
		return os;
	}

	friend istream& operator >> (istream& is, Product& temp)
	{
		cout << "������� ������������:" << endl;
		is >> temp.name;
		cout << "������� ����: " << endl;
		is >> temp.cost;
		cout << "������� ���: " << endl;
		is >> temp.weight;
		cout << "������� ����������: " << endl;
		is >> temp.theNumber;
		return is;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setPrice(float cost)
	{
		this->cost = cost;
	}

	float getPrice()
	{
		return cost;
	}

	void setWeight(float weight)
	{
		this->weight = weight;
	}

	float getWeight()
	{
		return weight;
	}

	void setTheNumber(int theNumber)
	{
		this->theNumber = theNumber;
	}

	void changeTheNumber(int theNumber)
	{
		this->theNumber = this->theNumber - theNumber;
	}

	int getTheNumber()
	{
		return theNumber;
	}

	~Product()
	{
	}

}; 
