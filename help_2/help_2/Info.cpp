#include "Info.h"


Info::Info() :Product()
{
	salary = this->add_maloc();
	experience = this->add_maloc();
}


Info::~Info()
{
	delete[]experience;
	delete[]salary;
}


Info::Info(const Info&ob) :Product(ob)
{
	int flag = 0;
	do
	{
		try
		{
			set_new_handler(error_alloc);
			salary = new char[strlen(ob.salary) + 1];
			experience = new char[strlen(ob.experience) + 1];
			try
			{
				if (strcpy_s(salary, strlen(ob.salary) + 1, ob.salary))
				{
					throw CopyError();
				}
				if (strcpy_s(experience, strlen(ob.experience) + 1, ob.experience))
				{
					throw CopyError();
				}
			}
			catch (CopyError ob)
			{
				cerr << "Error : ";
				ob.what();
			}
		}
		catch (...)
		{
			flag = 1;
		}
	} while (flag);
}

void Info::set_salary()
{
	cin.clear();
	set_number("¬ведите цену : ", salary, 5);
	kol += atoi(salary);
}
void Info::set_experience()
{
	cin.clear();
	set_number("¬ведите количество: ", experience, 2);
}
void Info::set_all()
{
	Product::set_all();
	set_salary();
	set_experience();
}

char* Info::get_salary()
{
	char* s;
	s = new char[strlen(salary) + 1];
	strcpy_s(s, strlen(salary) + 1, salary);
	return s;
}
char* Info::get_experience()
{
	char* s;
	s = new char[strlen(experience) + 1];
	strcpy_s(s, strlen(experience) + 1, experience);
	return s;
}
void Info::get_all()
{
	Product::get_all();
	cout << left << setw(10) << get_salary();
	cout << left << setw(10) << get_experience();
}


Info& Info::operator=(Info& ob)
{
	set_new_handler(error_alloc);
	if (this != &ob)
	{
		name = new char[strlen(ob.name) + 1];
		age = new char[strlen(ob.age) + 1];
		salary = new char[strlen(ob.salary) + 1];
		experience = new char[strlen(ob.experience) + 1];
		try
		{
			if (strcpy_s(name, strlen(ob.name) + 1, ob.name))
			{
				throw CopyError();
			}
			if (strcpy_s(age, strlen(ob.age) + 1, ob.age))
			{
				throw CopyError();
			}
			if (strcpy_s(salary, strlen(ob.salary) + 1, ob.salary))
			{
				throw CopyError();
			}
			if (strcpy_s(experience, strlen(ob.experience) + 1, ob.experience))
			{
				throw CopyError();
			}
		}
		catch (CopyError ob)
		{
			cerr << "Error " << endl;
			ob.what();
		}
	}
	return *this;
}
ostream& operator<<(ostream&out, const Info ob)
{
	out << ob.name << endl;
	out << ob.age << endl;
	out << ob.salary << endl;
	out << ob.experience << endl;
	return out;
}
istream& operator>>(istream&in, Info&ob)
{

	in >> ob.name;
	in >> ob.age;
	in >> ob.salary;
	in >> ob.experience;
	return in;
}
void Info::out_file()
{
	Info temp;
	ifstream file("file.txt", ios_base::in);
	int state = file.rdstate();
	try
	{
		if (state)
		{
			if (state&ios::badbit)
			{
				throw FileError();
			}
			else if (state&ios::eofbit)
			{
				throw NullFileError();
			}
		}
		else
		while (file >> temp)
			cout << temp;
	}
	catch (NullFileError ob)
	{
		cout << ERROR_MESSAGE;
		ob.what();
		cout << endl;
	}
	catch (FileError ob)
	{
		cout << ERROR_MESSAGE;
		ob.what("file.txt");
		cout << endl;
	}
	file.close();
	return;
}