#pragma once

#include "list.h"

template <typename T>
class Polynom
{
private:
	List<T> body;
	ULLI l;

public:

	Polynom()
	{
		l = 0;
	}
	Polynom(Polynom &a)
	{
		l = 0;
		Element<T> *c = a.body.getlast();
		while (c)
		{
			append(*c);
			c = c->getprev();
		}
	}


	void wipe()
	{
		l = 0;
		body.~List();
	}

	void in();

	void out();

	void append(Element<T> &a) // Новое старшее слагаемое
	{
		body.ath(a);
		l++;
		if (l == 0)
		{
			throw 1; // Счётчик переполнился
		}
	}



	void operator=(Polynom &a)
	{
		l = 0;
		Element<T> *c = a.body.getlast();
		while (c)
		{
			append(*c);
			c = c->getprev();
		}
	}

	Polynom operator+(Polynom &a)
	{
		Polynom res;
		Element<T> *e1 = body.getlast(), *e2 = a.body.getlast();
		while ((e1 != 0)*(e2 != 0))
		{
			res.append(*e1 + *e2);
			e1 = e1->getprev();
			e2 = e2->getprev();
		}
		while (e1)
		{
			res.append(*e1);
			e1 = e1->getprev();
		}
		while (e2)
		{
			res.append(*e2);
			e2 = e2->getprev();
		}
		return Polynom(res);
	}

	Polynom operator-(Polynom &a)
	{
		Polynom res;
		Element<T> *e1 = body.getlast(), *e2 = a.body.getlast();
		while ((e1 != 0)*(e2 != 0))
		{
			res.append(*e1 - *e2);
			e1 = e1->getprev();
			e2 = e2->getprev();
		}
		while (e1)
		{
			res.append(*e1);
			e1 = e1->getprev();
		}
		while (e2)
		{
			res.append(*e2);
			e2 = e2->getprev();
		}
		return Polynom(res);
	}

	Polynom operator*(Element<T> &a)
	{
		Polynom res;
		Element<T> *c = body.last;
		while (c)
		{
			res.append(*c*a);
			c = c->prev;
		}
		return Polynom(res);
	}

	Polynom operator*(Polynom &b)	//То же, что и композиция
	{								//Алгоритм неоптимальный, но кодить другой в лом, да и всё равно O(n*m)
		if (l < b.l)
		{
			return (b * *this);
		}
		else
		{
			Polynom res;
			Element<T> *s = body.getlast();
			Element<T> *ca = s, *cb = b.body.getlast();
			Element<T> c;
			while (cb)
			{
				cb = b.body.getlast();
				ca = s;
				c = Element<T>(T(0));
				while (ca)
				{
					c = c + *ca * *cb;
					ca = ca->getnext();
					cb = cb->getprev();
				}
				res.append(c);
				s = s->getprev();
			}
			while (s)
			{
				ca = s;
				cb = b.body.getlast();
				c = Element<T>(.0);
				while (cb)
				{
					c = c + *ca * *cb;
					ca = ca->getnext();
					cb = cb->getprev();
				}
				res.append(c);
				s = s->getprev();
			}
			s = b.body.getlast()->getprev();
			while (s)
			{
				cb = s;
				ca = body.getfirst();
				c = Element<T>(.0);
				while (cb)
				{
					c = c + *ca * *cb;
					ca = ca->getnext();
					cb = cb->getprev();
				}
				res.append(c);
				s = s->getprev();
			}
			return Polynom(res);
		}
	}



	T operator()(T x)
	{
		T result = 0, mul = 1;
		Element<T> *c = body.getlast();
		while (c)
		{
			result = result + c->get() * mul;
			mul = mul * x;
			c = c->getprev();
		}
		return T(result);
	}


	~Polynom()
	{
		body.~List();
	}
};