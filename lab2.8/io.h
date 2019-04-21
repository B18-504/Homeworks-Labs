#pragma once  //тут мы связываем объекты из проги с CIO

#include "CIO.h"


void i(Cpx &a)
{
	reqloopd(a.re, "Действительная часть: ");
	reqloopd(a.im, "Мнимая часть: ");
}

void i(double &a)
{
	getloopd(a);
}

void o(Cpx &a)
{
	cout << a.re << " + i*" << a.im;
}

void o(double a)
{
	cout << a;
}

template <typename T>
void Element<T>::in()
{
	i(body);
	FLUSH;
}

template <typename T>
void Element<T>::out()
{
	o(body);
}

template <typename T>
void Polynom<T>::in()
{
	wipe();
	ULLI n;
	reqloopulli(n, "Введите длину многочлена (старшая степень минус 1): ");
	cout << "Ввод коэффициэнтов происхоидт в порядке возрастания\n";
	Element<T> b;
	for (ULLI i = 0; i < n; i++)
	{
		b.in();
		append(b);
	}
}

template <typename T>
void Polynom<T>::out()
{
	cout << "Многочлен: \n";
	Element<T> *c = body.getfirst();
	for (ULLI i = l; i > 0; i--)
	{
		cout << '(';
		c->out();
		cout << ")*x^" << i - 1 << " + ";
		c = c->getnext();
	}
	cout << '\n';
}