#pragma once  //��� �� ��������� ������� �� ����� � CIO

#include "CIO.h"


void i(Cpx &a)
{
	reqloopd(a.re, "�������������� �����: ");
	reqloopd(a.im, "������ �����: ");
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
	reqloopulli(n, "������� ����� ���������� (������� ������� ����� 1): ");
	cout << "���� ������������� ���������� � ������� �����������\n";
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
	cout << "���������: \n";
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