#pragma once

#define ULLI unsigned long long int

#include "element.h"

/*class element //���������� �������� t - c � d
{
public:
	void *body;
	char t = 0;
	element *prev, *next;

	element()
	{
		body = 0;
	}
	element(double r, char type = 'd', element *p = 0, element *n = 0)	// 1 - �������� ������ ���� ������ (char type)
	{																	// ������������� �� ������ doubl-�, �� ��������� ����� ��������������
		t = type;
		prev = p;
		next = n;
		if (type == 'd')
		{
			body = new double(r);
		}
		else if (type == 'c')
		{
			body = new cpx(r, 0);
		}
		else
		{
			throw 1;
		}
	}
	element(double r, double i, element *p = 0, element *n = 0)			// ������������� ��� �����������
	{
		t = 'c';
		prev = p;
		next = n;
		body = new cpx(r, i);
	}
	element(cpx &a, element *p = 0, element *n = 0)						// --//--
	{
		t = 'c';
		prev = p;
		next = n;
		body = new cpx(a);
	}
	element(element &a, element *p = 0, element *n = 0)
	{
		t = a.t;
		prev = p;
		next = n;
		if (t == 'c')
		{
			body = new cpx(*(cpx*)a.body);
		}
		else if (t == 'd')
		{
			body = new double(*(double*)a.body);
		}
		else
		{
			throw 1;
		}
	}



	void operator=(element &a)											// 1 - ������ ������� ����� ������������ ������ ���� (t)
	{																	// �������������� ��������
		if (t != a.t)
		{
			t = a.t;
			delete body;
			if (a.t == 'c')
			{
				body = new cpx(*(cpx*)a.body);
			}
			else if (a.t == 'd')
			{
				body = new double(*(double*)a.body);
			}
			else
			{
				throw 1;
			}
		}
		else
		{
			if (a.t == 'c')
			{
				*(cpx*)body = *(cpx*)a.body;
			}
			else if (a.t == 'd')
			{
				*(double*)body = *(double*)a.body;
			}
			else
			{
				throw 1;
			}
		}
	}


	element operator+(element &a)										// 1 - ������������ ������������� �������� (t)
	{																	// ����������
		if ((t == 'c') * (a.t == 'c'))
		{
			return element(*(cpx*)body + *(cpx*)a.body);
		}
		else if ((t == 'c') * (a.t == 'd'))
		{
			return element(*(cpx*)body + *(double*)a.body);
		}
		else if ((t == 'd') * (a.t == 'c'))
		{
			return element (cpx(*(cpx*)a.body + *(double*)body));
		}
		else if ((t == 'd') * (a.t == 'd'))
		{
			return element (*(double*)body + *(double*)a.body, 'd');
		}
		else
		{
			throw 1;
		}
	}

	element operator-(element &a) //1 - ������������ ������������� �������� (t)
	{
		if ((t == 'c') * (a.t == 'c'))
		{
			return element(*(cpx*)body - *(cpx*)a.body);
		}
		else if ((t == 'c') * (a.t == 'd'))
		{
			return element(*(cpx*)body - *(double*)a.body);
		}
		else if ((t == 'd') * (a.t == 'c'))
		{
			return element(cpx(*(cpx*)a.body - *(double*)body));
		}
		else if ((t == 'd') * (a.t == 'd'))
		{
			return element(*(double*)body - *(double*)a.body, 'd');
		}
		else
		{
			throw 1;
		}
	}

	element operator*(element &a) //1 - ������������ ������������� �������� (t)
	{
		if ((t == 'c') * (a.t == 'c'))
		{
			return element(*(cpx*)body * *(cpx*)a.body);
		}
		else if ((t == 'c') * (a.t == 'd'))
		{
			return element(*(cpx*)body * *(double*)a.body);
		}
		else if ((t == 'd') * (a.t == 'c'))
		{
			return element(cpx(*(cpx*)a.body * *(double*)body));
		}
		else if ((t == 'd') * (a.t == 'd'))
		{
			return element(*(double*)body * *(double*)a.body, 'd');
		}
		else
		{
			throw 1;
		}
	}

	element operator/(element &a) //1 - ������������ ������������� �������� (t)
	{
		if ((t == 'c') * (a.t == 'c'))
		{
			return element(*(cpx*)body / *(cpx*)a.body);
		}
		else if ((t == 'c') * (a.t == 'd'))
		{
			return element(*(cpx*)body / *(double*)a.body);
		}
		else if ((t == 'd') * (a.t == 'c'))
		{
			return element(cpx(*(double*)body) / *(cpx*)a.body);
		}
		else if ((t == 'd') * (a.t == 'd'))
		{
			return element(*(double*)body / *(double*)a.body, 'd');
		}
		else
		{
			throw 1;
		}
	}



	~element()
	{
		delete body;
	}
};*/

template <typename T>
class List														// ��������������� ������, ����� ������ � �����
{
private:
	Element<T> *first, *last;

public:
	

	List()
	{
		first = 0;
		last = 0;
	}

	Element<T> *getfirst()
	{
		return first;
	}
	Element<T> *getlast()
	{
		return last;
	}


	void ate(Element<T> &a)										// ���������� �������� � ����� (����� ���������)
	{															// ��� ������� ������� ����� ������� ������������ � ����� ����������� ����������
		if (first)
		{
			last->setnext(new Element<T>(a.get(), last));
			last = last->getnext();
		}
		else
		{
			first = new Element<T>(a);
			last = first;
		}
	}

	void ath(Element<T> &a)										// ���������� � ������...
	{
		if (first)
		{
			first->setprev(new Element<T>(a.get(), 0, first));
			first = first->getprev();
		}
		else
		{
			first = new Element<T>(a);
			last = first;
		}
	}



	~List()														// �������� �� ������
	{
		if (first)
		{
			while (first->getnext())
			{
				first = first->getnext();
				delete first->getprev();
			}
			delete first;
			last = 0;
			first = 0;
		}
	}
};