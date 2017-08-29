#include "Exceptions.h"
using namespace std;

Exclusion::Exclusion()
{
	st = new char[20];
}


Exclusion::Exclusion(const Exclusion&A)
{
	st = new char[strlen(A.st) + 1];
	strcpy_s(st, strlen(A.st) + 1, A.st);
}

Exclusion::Exclusion(char *S)
{
	st = new char(strlen(S) + 1);
	strcpy_s(st, strlen(S) + 1, S);
}

Exclusion::~Exclusion()
{
	delete[]st;
}

void Exclusion::what()
{
	std::cout << st << endl;
}

void StringError::what()
{
	cout << "Line input error" << endl; //ошибка ввода строки
}

void bad_alloc1::what()
{
	cout << "Memory allocation error" << endl; //Ошибка выделения памяти
}

void NumberError::what()
{
	cout << "Input error" << endl; //ошибка ввода числа
}

void ArrayError::what()
{
	cout << "Going beyond the array" << endl; //Выход за пределы массива
}

void NullFileError::what()
{
	cout << "No data in the file" << endl;
}
void FileError::what(char*s)
{
	cout << "Error opening the file: " << s << endl;
}
void DivisionError::what()
{
	cout << "Error, division by zero" << endl;
}
void EnteryError::what()
{
	cout << "Incorrect data entry" << endl;
}
void CopyError::what()
{
	cout << "Copy error" << endl;
}
void term_func()
{
	cerr << "Program termination function\n";
	exit(1);
}
void error_alloc()
{
	cout << "Function, error of memory allocation" << endl;
	exit(1);
}
void error_copy(void)
{
	cout << "Function, error of copy element" << endl;
	exit(1);
}