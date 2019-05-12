#pragma once

#define ULLI unsigned long long int

#include "element.h"

template <typename T>
class List														//Bidirected list, knows only where its head and end are
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


	void ate(T &a)										//Add To the End (via creating new entry)
	{															//Merging an existing Element with the List can be also added
		if (first)
		{
			last->setnext(new Element<T>(a, last));
			last = last->getnext();
		}
		else
		{
			first = new Element<T>(a);
			last = first;
		}
	}

	void ath(T &a)										//Head...
	{
		if (first)
		{
			first->setprev(new Element<T>(a, 0, first));
			first = first->getprev();
		}
		else
		{
			first = new Element<T>(a);
			last = first;
		}
	}

	void sort()
	{
		T buff;
		if (last)
		{
			Element<T> *start = last->getprev(), *c;
			while (start)
			{
				c = start;
				while (c->getnext())
				{
					if (*c > *c->getnext())
					{
						buff = c->get();
						c->set(c->getnext()->get());
						c->getnext()->set(buff);
					}
					c = c->getnext();
				}
				start = start->getprev();
			}
		}
	}

	void map(void F(T&))
	{
		Element<T> *c = first;
		while (c)
		{
			c->apply(F);
			c = c->getnext();
		}
	}

	void where(bool F(T&))
	{
		Element<T> *c = first, *p;
		while (c)
		{
			if (!(c->apply(F)))
			{
				if (c->getprev())
				{
					c->getprev()->setnext(c->getnext());
				}
				if (c->getnext())
				{
					c->getnext()->setprev(c->getprev());
				}
				if (c == last)
				{
					last = c->getprev();
				}
				if (c == first)
				{
					first = c->getnext();
				}
				p = c;
				c = c->getnext();
				p->setnext(0);
				p->setprev(0);
				delete p;
			}
			else
			{
				c = c->getnext();
			}
		}
	}

	void reduce(void F(T&, T&), T& a)
	{
		Element<T> *c = first;
		while (c)
		{
			F(a, c->get());
			c = c->getnext();
		}
	}

	void merge(List &a)
	{
		last->setnext(a.first);
		a.first->setprev(last);
		last = a.last;
		a.first = 0;
		a.last = 0;
	}

	void slice(List &a, int strt, int end)
	{
		a.wipe();
		Element<T> *c = first;
		int i = 0;
		while ((c != 0) * (i < end))
		{
			if (i >= strt)
			{
				a.ate(c->get());
			}
			c = c->getnext();
			i++;
		}
	}

	void search(List &a, int &i)
	{
		i = -1;
		int n = 0;
		bool f = 1;
		Element<T> *c = first, *l = a.first;
		while ((f)*(c!=0))
		{
			if (c->get() == l->get())
			{
				l = l->getnext();
				if (i == -1)
				{
					i = n;
				}
				if (!l)
				{
					f = 0;
				}
			}
			else
			{
				l = a.first;
				i = -1;
			}
			c = c->getnext();
			n++;
		}
		if (f)
		{
			i = -1;
		}
	}

	void cut(List &a, int i)
	{
		a.wipe();
		int n = 0;
		Element<T> *c = first;
		while (c)
		{
			if (n == i)
			{
				a.first = c;
				a.last = last;
				last = c->getprev();
				if (!last)
				{
					first = 0;
				}
				else
				{
					last->setnext(0);
				}
				a.first->setprev(0);
				c = 0;
			}
			else 
			{
				c = c->getnext();
				n++;
			}
		}
	}

	void in();

	void out();

	void wipe()
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

	~List()														//Iterating through the list...
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