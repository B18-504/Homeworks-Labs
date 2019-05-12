#pragma once

#include "CIO.h"

void Int::in()
{
	reqloopi(body, "Введите целое: ");
}

void Int::out()
{
	cout << body;
}

void Cpx::in()
{
	reqloopd(re, "Действительная часть: ");
	reqloopd(im, "Мнимая часть: ");
}

void Cpx::out()
{
	cout << re << " + i*" << im;
}

void Strg::in()
{
	cout << "Введите строку: ";
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
	reqloopch(r, "yn", "Ещё элемент? (y/n): ");
	while (r == 'y')
	{
		buff.in();
		ate(buff);
		reqloopch(r, "yn", "Ещё элемент? (y/n): ");
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