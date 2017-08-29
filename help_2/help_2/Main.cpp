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
		cout << "1) Добавить товар \n2) Показать все товары \n3) Средняя цена \n4) Выход\n";
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
						  int state = file.rdstate(); //чтение сост потока
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
						  cout << "Ошибка ввода : ";
						  ob.what();
						  cout << endl;
						  getchar();
						  cin.clear();
					  }
					  catch (FileError ob)
					  {
						  cout << "Ошибка ввода : ";
						  ob.what("file.txt");
						  cout << endl;
						  getchar();
						  cin.clear();
					  }
					  catch (...)
					  {
						  cout << "неизвестная ошибка" << endl;
						  getchar();
						  cin.clear();
					  }
				  }
				  catch (ArrayError ob)
				  {
					  cout << "Ошибка ввода : ";
					  ob.what();
					  cout << endl;
					  getchar();
					  cin.clear();
				  }
		}
			break;
		case 2:
		{
				  cout << left << setw(13) << "Наименование|" << setw(5) << "Вес|" << setw(7) << "Цена|";
				  cout << left << setw(10) << "Количество" << endl << endl;
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
					  cin.flags(ios::fixed);//при выводе чисел с плавающей точкой три знака после зпт
					  cin.precision(3);
					  averageSalery = Info::kol / temp;
					  cout << "Средняя цена: " << averageSalery << endl;
					  getchar();
					  cin.clear();
				  }
				  catch (DivisionError ob)
				  {
					  cout << "Ошибка ввода : ";
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