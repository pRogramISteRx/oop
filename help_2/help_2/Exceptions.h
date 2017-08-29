#pragma once
#include<iostream>
using namespace std;

void term_func();

class Exclusion : public exception
{
	char*st;
public:
	Exclusion();
	Exclusion(const Exclusion&);
	Exclusion(char*);
	~Exclusion();
	void what();
};

//Ошибка выделения памяти
class bad_alloc1 :public Exclusion
{
public:
	void what();

};

//ошибка ввода строки
class StringError :public Exclusion
{
public:
	void what();
};

//ошибка ввода числа
class NumberError :public Exclusion
{
public:
	void what();
};

//Выход за пределы массива
class ArrayError :public Exclusion
{
public:
	void what();
};

//отсутствие данных в файле
class NullFileError :public Exclusion
{
public:
	void what();
};

//ошибка открытия файла
class FileError :public Exclusion
{
public:
	void what(char*);
};

//ошибка, деление на нуль
class DivisionError :public Exclusion
{
public:
	void what();

};

//некорректный ввод данных
class EnteryError :public Exclusion
{
public:
	void what();
};

//класс ошибка копирования
class CopyError :public Exclusion
{
public:
	void what();
};

//функция, ошибка выделения памяти
void error_alloc(void);

//функция, ошибка копирования элемента
void error_copy(void);
