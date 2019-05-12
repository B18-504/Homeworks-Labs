#pragma once

template <typename T>
class Element
{
private:
	T body;
	Element *next = 0, *prev = 0;

public:
	Element()
	{
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

	bool operator>(Element &a)
	{
		return(body > a.body);
	}

	void apply(void F(T&))
	{
		F(body);
	}

	bool apply(bool F(T&))
	{
		return(F(body));
	}

	void in();

	void out();

};