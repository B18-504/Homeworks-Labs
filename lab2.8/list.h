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


	void ate(Element<T> &a)										//Add To the End (via creating new entry)
	{															//Merging an existing Element with the List can be also added
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

	void ath(Element<T> &a)										//Head...
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



	~List()														//Iterating throug the list...
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