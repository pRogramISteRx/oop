#pragma once
#include<fstream>
#include<iostream>
#include<ctime>
#include"Exceptions.h"
#include"Functions.h"
#include<iomanip>

#define ERROR_MESSAGE "An exception occurred : "

using  namespace std;
class Product
{
protected:
	char* age;
	char* name;
	void set_number(char*, char*, short);
	void set_string(char*, char*, short);
	char*  add_maloc();
public:
	Product();
	Product(const Product&);
	virtual ~Product() = 0;
	void set_age();
	void set_name();
	void set_all();
	/*char* get_age();
	char* get_name();
	char* get_first_name();
	char* get_patronymic();*/
	char* get_dat(char*);
	void get_all();
};
void my_func()throw (int);