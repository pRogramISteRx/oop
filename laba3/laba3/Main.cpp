#include <iostream>
#include "Menu.h"
#include <locale>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu<Product> m;
	m.MainMenu();
}