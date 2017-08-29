#include <iostream>
#include "ShablonList.h"
#include "Product.h"
#include <Windows.h>
#include "Iterator.h"
#include <string.h>
using namespace std;

template <class T>
class menu
{
	bool isExit;
	int a;
	ShablonList<Product> list;
	Product pr;
public:
	menu()
	{
		isExit = true;
		a = 0;
	}
	void MainMenu()
	{
		while (isExit)
		{
			cout << "1.Добавить элемент"<< endl;
			cout << "2.Удалить элемент"<< endl;
			cout << "3.Распечатать список"<< endl;
			cout << "4.Найти элемент в списке"<< endl;
			cout << "5.Поменять элементы местами"<< endl;
			cout << "6.Выйти" << endl;
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cin >> pr;
				list.addElementHead(pr);
				break;
			}

			case 2:
			{
				int a = 0;
				cout << "Введите номер удаляемого элемента: " << "[1;" << list.getElementsCount() << "]" << endl;
				cin >> a;
				while (a < 1 || a > list.getElementsCount())
					cin >> a;
				list.deleteElement(a);
				break;
			}

			case 3:
			{
				Iterator<Product> it;
				for (it = list.begin(); it.eos(); ++it)
					cout << it;

				cout << "Инверсия: " << endl;
				cout << "-------------------------\n";
				for (it = list.rBegin(); it.eos(); --it)
					cout << it;
				//list.printAllElements();

				cout << "------------------------- " << endl;
				break;
			}

			case 4:
			{
				Iterator<Product> it;
				string name;
				cout << "Введите наименование товара: " << endl;
				cin >> name;
				for (it = list.begin(); it.eos(); ++it)
				{
					if (it.getPtr()->getData().getName() == name)
						cout << it;
				}
				cout << "------------------------- " << endl;
				break;
			}

			case 5:
			{
				int first, second;
				cout << "Введите номера элементов которые вы хотите поменять" << endl;
				Iterator<Product> it(list.begin());
				it = list.begin();
				//cout << it[1];
				it = list.begin();
				//cout << it[2];
				it = list.begin();
				//cout << it[3];
				cin >> first >> second;
				first--;
				second--;
				//Iterator<Product> it;
				////Iterator<Product> it1;
				Iterator<Product> buf;
				it = list.begin();
				buf = list.begin();
				cout << "it : " << it << endl;
				buf = it[first];
				cout << "buf: " << buf << endl;
				cout << "second" << it[second] << endl;
				it[first] = it[second];
				it[second] = buf;
				cout << "первый: " << it[first];
				cout << "второй: " << it[second];
				/*buf = it[first];
				cout <<"первый: "<< it[first];
				it[first] = it1[second];
				cout <<"второй: " << it[second];
				it[second] = buf;
				cout << it[2];*/

				/*for (it = list.begin(); it.eos(); it++)
				cout << it;*/

				cout << "------------------------- " << endl;
				break;

			}

			case 6:
			{
				isExit = false;
				break;
			}

			default:
			{
				cout << "Неверный ввод!" << endl;
				cin >> a;
			}
			}
		}
	}
	
}; 
