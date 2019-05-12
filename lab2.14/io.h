#pragma once

#include "CIO.h"

void Int::in()
{
	reqloopi(body, "������� �����: ");
}

void Int::out()
{
	cout << body;
}

void Cpx::in()
{
	reqloopd(re, "�������������� �����: ");
	reqloopd(im, "������ �����: ");
}

void Cpx::out()
{
	cout << re << " + i*" << im;
}

void Strg::in()
{
	cout << "������� ������: ";
	cin >> body;
}

void Strg::out()
{
	cout << body;
}

template <typename T>
void Element<T>::in()
{
	body.in();
}

template <typename T>
void Element<T>::out()
{
	body.out();
}

template <typename T>
void List<T>::in()
{
	T buff;
	char r;
	reqloopch(r, "yn", "��� �������? (y/n): ");
	while (r == 'y')
	{
		buff.in();
		ate(buff);
		reqloopch(r, "yn", "��� �������? (y/n): ");
	}
}

template <typename T>
void List<T>::out()
{
	Element<T> *c = first;
	while (c)
	{
		c->out();
		cout << ' ';
		c = c->getnext();
	}
}