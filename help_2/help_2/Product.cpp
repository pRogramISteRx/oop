#include "Product.h"

void Product::set_number(char*str, char*name, short number)
{
	int flag;
	do
	{
		flag = 0;
		try
		{
			cout << str;
			cin.clear();
			cin >> name;
			for (int i = 0; i < strlen(name); i++)
			if (*(name + i) < '0' || *(name + i) > '9')
			{
				throw NumberError();
			}
			if (strlen(name)>number)
			{
				throw EnteryError();
			}
		}
		catch (NumberError a)
		{
			flag = 1;
			a.what();
		}
		catch (EnteryError ob)
		{
			flag = 1;
			ob.what();
		}
		catch (...)
		{
			flag = 1;
			cout << "Error ***" << endl;
		}
	} while (flag);
}


void Product::set_string(char*str, char*name, short number)
{
	int flag;
	do
	{
		flag = 0;
		try
		{
			cout << str;
			cin >> name;
			for (int i = 0; i < strlen(name); i++)
			if (*(name + i) >= '0' && *(name + i) <= '9')
			{
				throw StringError();
			}
			if (strlen(name)>number)
			{
				throw EnteryError();
			}
		}
		catch (StringError a)
		{
			flag = 1;
			a.what();
		}
		catch (EnteryError ob)
		{
			flag = 1;
			ob.what();
		}
		catch (...)
		{
			flag = 1;
			cout << "Error ***" << endl;
		}
	} while (flag);
}

Product::Product()
{
	name = this->add_maloc();
	age = this->add_maloc();
}


void my_func()throw (int)
{
	throw 'x';
}

Product::Product(const Product&ob)
{
	set_unexpected(error_copy);
	set_new_handler(error_alloc);
	int flag = 0;
	do
	{
		flag = 0;
		try
		{
			name = new char[strlen(ob.name) + 1];
			age = new char[strlen(ob.age) + 1];
			if (strcpy_s(name, strlen(ob.name) + 1, ob.name))
			{
				throw CopyError();
			}
			if (strcpy_s(age, strlen(ob.age) + 1, ob.age))
			{
				throw CopyError();
			}
		}
		catch (CopyError ob)
		{
			cerr << "Error";
			ob.what();
		}
	} while (flag);
}


Product::~Product()
{
	delete[]age;
	delete[]name;
}


void Product::set_age()
{
	set_number("¬ведите вес : ", age, 4);
}


void Product::set_name()
{
	set_string("¬ведите наименование : ", name, 10);
}

void Product::set_all()
{
	set_name();
	set_age();
}

char* Product::get_dat(char*data)
{
	char* s = new char[strlen(data) + 1];
	strcpy_s(s, strlen(data) + 1, data);
	return s;
}

void Product::get_all()
{
	cout << left << setw(13) << get_dat(name);
	cout << left << setw(5) << get_dat(age);
}


char* Product::add_maloc()
{
	char *s;
	int flag = 0;
	do
	{
		flag = 0;
		try
		{
			if (!(s = new char[20]))
			{
				throw bad_alloc1();
				flag = 1;
			}
			else
				return s;
		}
		catch (bad_alloc1 exep)
		{
			cout << ERROR_MESSAGE;
			exep.what();
			cout << endl;
		}
	} while (flag);
	return 0;
}