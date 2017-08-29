#pragma once;
using namespace std;
template<class T>
class Element
{
	T data;
	Element<T> *next;
	Element<T> *priv;

	friend ostream& operator<< (ostream &os, Element<T> &temp)
	{
		os << temp->getData();
		return os;
	}

public:
	Element()
	{
		next = NULL;
		priv = NULL;
	}

	explicit Element(T &newdata)
	{
		data = newdata;
		next = nullptr;
	}

	~Element() { cout << "~Element" << endl; }

	//--------------------------------------------
	Element* getNext()
	{
		return next;
	}

	Element* getPriv()
	{
		return priv;
	}


	T& getData()
	{
		return data;
	}

	//--------------------------------------------
	void setNext(Element<T> *temp)
	{
		next = temp;
	}

	void setPriv(Element<T> *temp)
	{
		priv = temp;
	}

	void setData(Element<T> *temp)
	{
		data = temp->getData();
	}

	void setData(T& temp)
	{
		data = temp;
	}

}; 
