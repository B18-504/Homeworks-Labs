#pragma once  //��� �� ��������� ������� �� ����� � CIO

#include "CIO.h"


void Cpxin(Cpx &a)
{
	reqloopd(a.re, "�������������� �����: ");
	reqloopd(a.im, "������ �����: ");
}

void Cpxout(Cpx &a, char *end = 0)
{
	cout << a.re << " + i*" << a.im << end;
}

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
	reqloopulli(n, "������� ����� ���������� (������� ������� - 1): ");
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

/*void elout(element &a, char *end)
{
	if (a.t == 'c')
	{
		Cpxout(*(Cpx*)a.body, end);
	}
	else if (a.t == 'd')
	{
		cout << *(double*)a.body << end;
	}
}*/


/*
void polin(polynom &a)
{
	a.wipe();
	ULLI n;
	reqloopulli(n, "������� ����� ���������� (������� ������� - 1): ");
	cout << "���� ������������� ���������� � ������� �����������\n";
	element b;
	for (ULLI i = 0; i < n; i++)
	{
		elin(b);
		a.append(b);
	}
}
*/

/*
void polout(polynom &a)
{
	cout << "���������: \n";
	element *c = a.body.first;
	for (ULLI i = a.l; i > 0; i--)
	{
		cout << '(';
		elout(*c, ")*x^");
		cout << i - 1 << " + ";
		c = c->next;
	}
	cout << '\n';
}*/
