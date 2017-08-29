#pragma once
#include "Product.h"

class Info :public Product
{
private:

	char* salary;
	char* experience;
public:
	static int kol;
	Info();
	Info(const Info&);
	~Info();
	void get_all();
	char* get_experience();
	char* get_salary();
	void set_all();
	void set_experience();
	void set_salary();
	Info& operator =(Info&);
	friend ostream& operator<< (ostream&, const Info);
	friend istream& operator>>(istream&, Info&);
	void out_file();
};