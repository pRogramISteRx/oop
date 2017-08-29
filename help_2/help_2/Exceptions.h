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

//������ ��������� ������
class bad_alloc1 :public Exclusion
{
public:
	void what();

};

//������ ����� ������
class StringError :public Exclusion
{
public:
	void what();
};

//������ ����� �����
class NumberError :public Exclusion
{
public:
	void what();
};

//����� �� ������� �������
class ArrayError :public Exclusion
{
public:
	void what();
};

//���������� ������ � �����
class NullFileError :public Exclusion
{
public:
	void what();
};

//������ �������� �����
class FileError :public Exclusion
{
public:
	void what(char*);
};

//������, ������� �� ����
class DivisionError :public Exclusion
{
public:
	void what();

};

//������������ ���� ������
class EnteryError :public Exclusion
{
public:
	void what();
};

//����� ������ �����������
class CopyError :public Exclusion
{
public:
	void what();
};

//�������, ������ ��������� ������
void error_alloc(void);

//�������, ������ ����������� ��������
void error_copy(void);
