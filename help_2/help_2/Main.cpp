#include"Info.h"
#include"Exceptions.h"
#include<Windows.h>
#include<locale.h>
#include<fstream>
#include<iomanip>
#define N 5

int Info::kol = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	set_terminate(term_func);
	while (1)
	{
		system("cls");
		int temp = 0;
		Info c[N], a;
		ifstream file1("file.txt", ios::in);
		try
		{
			if (!file1)
			{
				throw FileError();
			}
		}
		catch (FileError ob)
		{
			cout << "Error ";
			ob.what("file.txt");
			cout << endl;
			_getch();
		}
		if (file1)
		{
			Info::kol = 0;
			while (file1 >> a)
			{
				c[temp++] = a;
				Info::kol += atoi(a.get_salary());
			}
		}
		/*else
		{
		Info::kol = 0;
		while (file1 >> a)
		{
		c[temp++] = a;
		Info::kol += atoi(a.get_salary());
		}
		}*/
		file1.close();
		system("cls");
		int choose;
		cin.clear();
		cout << "1) �������� ����� \n2) �������� ��� ������ \n3) ������� ���� \n4) �����\n";
		choose = menu(5);
		system("cls");
		switch (choose)
		{
		case 1:
		{
				  try
				  {
					  if (temp == 3)
					  {
						  throw ArrayError();
					  }
					  c[temp].set_all();
					  try
					  {

						  ofstream file("file.txt", ios_base::app);
						  int state = file.rdstate(); //������ ���� ������
						  if (state)
						  {
							  if (state&ios::badbit)
							  {
								  throw FileError();
							  }
							  if (state&ios::eofbit)
							  {
								  throw NullFileError();
							  }
						  }
						  file << c[temp++];
						  file.close();
					  }
					  catch (NullFileError ob)
					  {
						  cout << "������ ����� : ";
						  ob.what();
						  cout << endl;
						  getchar();
						  cin.clear();
					  }
					  catch (FileError ob)
					  {
						  cout << "������ ����� : ";
						  ob.what("file.txt");
						  cout << endl;
						  getchar();
						  cin.clear();
					  }
					  catch (...)
					  {
						  cout << "����������� ������" << endl;
						  getchar();
						  cin.clear();
					  }
				  }
				  catch (ArrayError ob)
				  {
					  cout << "������ ����� : ";
					  ob.what();
					  cout << endl;
					  getchar();
					  cin.clear();
				  }
		}
			break;
		case 2:
		{
				  cout << left << setw(13) << "������������|" << setw(5) << "���|" << setw(7) << "����|";
				  cout << left << setw(10) << "����������" << endl << endl;
				  for (int i = 0; i < temp; i++)
				  {
					  c[i].get_all();
					  cout << endl;
				  }
				  // cin.clear();
				  _getch();
				  cin.clear();
		}
			break;
		case 3:
		{
				  try
				  {
					  if (temp == 0)
					  {
						  throw DivisionError();
					  }
					  double averageSalery;
					  cin.flags(ios::fixed);//��� ������ ����� � ��������� ������ ��� ����� ����� ���
					  cin.precision(3);
					  averageSalery = Info::kol / temp;
					  cout << "������� ����: " << averageSalery << endl;
					  getchar();
					  cin.clear();
				  }
				  catch (DivisionError ob)
				  {
					  cout << "������ ����� : ";
					  ob.what();
					  cout << endl;
					  getchar();
					  cin.clear();
				  }
		}
			break;
		case 4: return 0;
		}
		file1.close();
	}
}