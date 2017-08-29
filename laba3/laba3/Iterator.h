
template <class T>
class Iterator
{
	Element<T> *p;
	Element<T> *begin;
	Element<T> *buf;

public:

	friend ostream& operator << (ostream& os, Iterator<T>& pr)
	{
		os << pr.p->getData();
		return os;
	}

	Iterator() { p = new Element<T>; }
	Iterator(Element<T> *temp)
	{
		p = temp;
		begin = temp;
		buf = NULL;
	}

	Iterator<T>& operator= (Element<T>* el)
	{
		this->p = el;
		return *this;
	}

	Iterator<T>& operator= (Iterator<T>& it)
	{
		this->p = it.getPtr();
		this->p->setData(it.getPtr());
		return *this;
	}

	Iterator<T>& operator++ ()
	{
		p = p->getNext();
		return *this;
	}

	bool operator==(Iterator<T>& it)
	{
		if (p == it.getPtr())
			return true;
		else
			return false;
	}

	bool operator!=(Iterator<T>& it)
	{
		if (p == it.getPtr())
			return true;
		else
			return false;
	}

	Iterator<T>& operator[] (int a)
	{
		buf = begin;
		while (a > 1)
		{
			buf = buf->getNext();
			a--;
		}
		this->p = buf;
		//a--;
		//}
		return *this;

	}

	Iterator<T>& operator-- ()
	{
		p = p->getPriv();
		return *this;
	}

	bool eos()
	{
		if (this->p == NULL) return false;
		if (this == NULL) return false;
		else return true;
	}

	Element<T>* getPtr()
	{
		return p;
	}
}; 
