#pragma once

#include "cpx.h"

template <typename T>
class Element
{
private:
	T body;
	Element *next = 0, *prev = 0;

public:
	Element(bool b = 0)
	{
		if (b)
		{
			in();
		}
	}
	Element(T a, Element *p = 0, Element *n = 0)
	{
		body = a;
		next = n;
		prev = p;
	}
	void set(T &a)
	{
		body = a;
	}
	void setnext(Element *a)
	{
		next = a;
	}
	void setprev(Element *a)
	{
		prev = a;
	}

	T get()
	{
		return T(body);
	}
	Element *getnext()
	{
		return next;
	}
	Element *getprev()
	{
		return prev;
	}

	void operator=(Element &a)
	{
		body = a.body;
	}
	Element operator+(Element &a)
	{
		return Element(body + a.body);
	}
	Element operator-(Element &a)
	{
		return Element(body - a.body);
	}
	Element operator*(Element &a)
	{
		return Element(body * a.body);
	}
	Element operator/(Element &a)
	{
		return Element(body / a.body);
	}

	void in();

	void out();

};