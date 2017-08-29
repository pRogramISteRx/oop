#include"Functions.h"
#include"Exceptions.h"
using namespace std;

int menu(int size)
{

	int choose;
	while (1)
	{
		char *buff = new char[50];
		cout << "Ваш выбор: \n";
		check_numbers(buff, 1);
		choose = atoi(buff);
		if (choose > 0 && choose <= size) return choose;
		delete[]buff;
	}
}


void check_numbers(char* str, int amount_of_the_number)
{
	int i = 0, check_enter = FALSE;
	char c;
	while (!check_enter)
	{
		while ((c = (int)_getch()) != 13) //enter
		{
			if (c == 8 && i > 0) //backspace
			{
				cout << "\b \b";
				i--;
			}
			if (i < amount_of_the_number)
			if (c >= 48 && c <= 57)
			{
				cout << (char)c;
				str[i] = (char)c;
				i++;
			}
			str[i] = '\0';
		}
		if (str[0] == '\0')
		{
			cout << "\nThe field is empty" << endl; //Поле не заполнено
		}
		else
		{
			check_enter = TRUE;
			cout << endl;
		}
	}
}
