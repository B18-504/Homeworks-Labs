#pragma once

#include "CIO.h"
#include "FIO.h"

void Cpx::in(char **p)
{
	reqloopd(re, p[0]);
	reqloopd(im, p[1]);
}

void Cpx::out(char **p)
{
	cout << re << p[0] << im << p[1];
}

void Dbl::in(char **p)
{
	reqloopd(body, *p);
}

void Dbl::out(char **p)
{
	cout << body << *p;
}

void Int::out(char **p)
{
	cout << body << *p;
}

template <typename T, int n>
void Tree<T, n>::Node::in(char **p)
{
	body.in(p);
}

template <typename T, int n>
void Tree<T, n>::Node::out(char **p)
{
	body.out(p);
}

template <typename T, int n>
void Tree<T, n>::in(char **p, int way[n + 1])
{
	wipe();
	char ch;
	Stack s;
	cout << *p;
	reqloopch(ch, "yn", *(p + 1));
	if (ch == 'y')
	{
		root = new Node;
	}
	Node *c = root;
	s.push(0);
	while (c)
	{
		if (s.get() == (n + 1))
		{
			c = c->getprev();
			s.pop();
		}
		else if (way[s.get()] == n)
		{
			c->in(p + 2);
			s.inc();
		}
		else
		{
			reqloopch(ch, "yn", *(p + 1));
			if (ch == 'y')
			{
				c->setnext(new Node(c), way[s.get()]);
				c = c->getnext(way[s.get()]);
				s.inc();
				s.push(0);
			}
			else
			{
				s.inc();
			}
		}
	}
}

template <typename T, int n>
void Tree<T, n>::out(char **p, int way[n + 1])
{
	cout << p[0];
	Stack s;
	Tree<T, n>::Node *c = root;
	if (c)
	{
		cout << p[1];
	}
	else
	{
		cout << p[2];
	}
	s.push(0);
	while (c)
	{
		if (s.get() == (n + 1))
		{
			c = c->getprev();
			s.pop();
		}
		else if (way[s.get()] == n)
		{
			c->out(p + 3);
			s.inc();
		}
		else
		{
			if (c->getnext(way[s.get()]))
			{
				cout << p[1];
				c = c->getnext(way[s.get()]);
				s.inc();
				s.push(0);
			}
			else
			{
				cout << p[2];
				s.inc();
			}
		}
	}
}

template <typename T>
void Element<T>::out(char **p)
{
	body.out(p);
}

template <typename T>
void List<T>::out(char **p)
{
	cout << *p;
	Element<T> *c = first;
	while (c)
	{
		c->out(p + 1);
		c = c->getnext();
	}
}