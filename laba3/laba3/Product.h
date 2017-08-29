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
		os << "Наименование: " << pr.getName() << endl <<
			"Цена товара: " << pr.getPrice() << endl <<
			"Вес товара: " << pr.getWeight() << endl <<
			"Количество товара: " << pr.getTheNumber() << endl;
		return os;
	}

	friend istream& operator >> (istream& is, Product& temp)
	{
		cout << "Введите наименование:" << endl;
		is >> temp.name;
		cout << "Введите цену: " << endl;
		is >> temp.cost;
		cout << "Введите вес: " << endl;
		is >> temp.weight;
		cout << "Введите количество: " << endl;
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
