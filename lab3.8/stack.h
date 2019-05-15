#pragma once

class Stack
{
private:
	class Elem
	{
	private:
		Elem *prev;
		int body;

	public:
		Elem(int a, Elem *p)
		{
			body = a;
			prev = p;
		}

		int get()
		{
			return body;
		}

		Elem *getprev()
		{
			return prev;
		}

		void inc()
		{
			body++;
		}

		~Elem()
		{
			prev = 0;
		}
	};

	Elem *head;

public:
	Stack()
	{
		head = 0;
	}

	void push(int a)
	{
		head = new Elem(a, head);
	}

	int pop()
	{
		if (head)
		{
			int a = head->get();
			Elem *p = head;
			head = head->getprev();
			delete p;
			return(a);
		}
		else
		{
			throw 1;
		}
	}

	void inc()
	{
		head->inc();
	}

	int get()
	{
		return head->get();
	}
};