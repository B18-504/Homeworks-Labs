#pragma once

#include "stack.h"
#include "list.h"

bool True = 1, False = 0;			//мегакостыль

template <typename T, int n>
class Tree
{
public: //private

	class Node
	{
	public: //private
		T body;
		Node **p = new Node*[n] {0};
		Node *prev;

	public:
		Node()
		{
			prev = 0;
		}
		Node(Node *a)
		{
			prev = a;
		}
		Node(T &a, Node *p)
		{
			body = a;
			prev = p;
		}

		void set(T &a)
		{
			body = T(a);
		}

		T get()
		{
			return T(body);
		}

		Node *getnext(char i)
		{
			return p[i];
		}

		void setnext(Node *a, int i)
		{
			p[i] = new Node(a->get(), this);
		}

		void setprev(Node *p)
		{
			prev = p;
		}

		Node *getprev()
		{
			return prev;
		}

		void in(char **);

		void out(char **);

		void wipe()
		{
			prev = 0;
			for (int i = 0; i < n; i++)
			{
				if (p[i])
				{
					p[i]->wipe();
					delete p[i];
					p[i] = 0;
				}
			}
		}

		~Node()
		{
			prev = 0;
			for (int i = 0; i < n; i++)
			{
				if (p[i])
				{
					p[i]->wipe();
					delete p[i];
					p[i] = 0;
				}
			}
		}
	};

	Node *root;

public:
	Tree()
	{
		root = 0;
	}

	void map(void F(T&))
	{
		Stack s;
		Node *c = root;
		s.push(0);
		while (c)
		{
			if (!s.get())
			{
				F(c->body);
				s.inc();
			}
			else if (s.get() == (n + 1))
			{
				c = c->getprev();
				s.pop();
			}
			else if (c->getnext(s.get()-1))
			{
				c = c->getnext(s.get() - 1);
				s.inc();
				s.push(0);
			}
			else
			{
				s.inc();
			}
		}
	}

	void in(char **, int[n + 1]);

	void out(char **, int[n + 1]);

	void wipe()
	{
		if (root)
		{
			root->wipe();
		}
	}

	~Tree()
	{
		if (root)
		{
			root->wipe();
		}
	}
	
};

template <typename T, int n>
class Line
{
private:
	List<bool> b;
	List<T> data;

public:
	Line()
	{}

	void set(Tree<T, n> &a, int way[n + 1])
	{
		wipe();
		Stack s;
		Tree<T, n>::Node *c = a.root;
		if (c)
		{
			b.ate(True);			//фигня какайта
		}
		else
		{
			b.ate(False);
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
				data.ate(c->body);
				s.inc();
			}
			else
			{
				if (c->getnext(way[s.get()]))
				{
					b.ate(True);
					c = c->getnext(way[s.get()]);
					s.inc();
					s.push(0);
				}
				else
				{
					b.ate(False);
					s.inc();
				}
			}
		}
	}

	void get(Tree<T, n> &a, int way[n + 1])
	{
		a.wipe();
		Stack s;
		bool kek;					//достаём револьверы
		bool &dummy = kek;
		b.take(dummy);
		if (kek)
		{
			a.root = new Tree<T, n>::Node;
		}
		Tree<T, n>::Node *c = a.root;
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
				data.take(c->body);
				s.inc();
			}
			else
			{
				b.take(dummy);
				if (kek)
				{
					c->setnext(new Tree<T, n>::Node(c), way[s.get()]);
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

	void wipe()
	{
		//
	}

	~Line()
	{
		//
	}
};