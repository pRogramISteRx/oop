#include<iostream>
#include"Element.h"
using namespace std;


template <class T>
class ShablonList
{
	Element<T> *head;
	Element<T> *tail;
	int elementsCount;
public:

	ShablonList()
	{
		head = NULL;
		tail = NULL;
		elementsCount = 0;
	}

	int getElementsCount()
	{
		return elementsCount;
	}

	Element<T>* begin()
	{
		return head;
	}

	Element<T>* rBegin()
	{
		return tail;
	}

	// ----------------------------------------------
	void addElementHead(T data)
	{
		if (head == NULL)
		{
			Element<T> *oneMore = new Element<T>(data);
			head = oneMore;
			head->setNext(NULL);
			tail = oneMore;
			elementsCount++;
		}
		else
		{
			Element<T> *oneMore = new Element<T>(data);
			oneMore->setNext(head);
			head->setPriv(oneMore);
			head = oneMore;
			elementsCount++;
		}
	}

	void deleteElement(int number)
	{
		if (elementsCount == 0)
		{
			cout << "В списке не хранится никакой информации! Сначала внесите какие-либо данные" << endl;
			return;
		}

		int count = 0;
		Element<T> *temp = head;

		for (int i = 0; i < elementsCount; i++)
		{
			count++;
			if (count == number)
				break;
			temp = temp->getNext();
		}

		if (count == 1 && (head->getNext()))
		{
			Element<T> *temp = head;
			head = head->getNext();
			head->setPriv(NULL);
			delete temp;
			elementsCount--;
			return;
		}
		else if (count == 1 && (head == tail))
		{
			head->setNext(NULL);
			head = NULL;
			delete head;
			elementsCount = 0;
			return;
		}

		if (elementsCount == count)
		{
			Element<T> *temp = tail;
			tail = tail->getPriv();
			tail->setNext(NULL);
			delete temp;
			elementsCount--;
			return;
		}

		temp = head;
		Element<T> *temp2;											  //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные
		for (int i = 0; i < (count - 1); i++) temp = temp->getNext();

		temp2 = temp;
		temp2->getPriv()->setNext(temp->getNext());
		temp2->getNext()->setPriv(temp->getPriv());
		delete temp;
		elementsCount--;									//Обязательно
	}

	void printAllElements()
	{
		Element<T> *temp = head;
		for (int i = 0; i < elementsCount; i++)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}

	void deleteAllelements()
	{
		if (head == NULL)
			return;

		while (head != NULL)
		{
			Element<T> *temp = head;
			head = temp->getNext();
			delete temp;
			elementsCount--;
		}
	}

	~ShablonList()
	{
		while (head)
		{
			tail = head->getNext();
			delete head;
			head = tail;
		}
	}
}; 
