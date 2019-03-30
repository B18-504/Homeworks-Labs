// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include "polynom.h"
#include "io.h"

#define t double
#define ULLI unsigned long long int

int main()
{
	setlocale(0, "RUS");
	Polynom<t> a, b;
	a.in();
	b.in();
	a = a * b;
	a.out();
	b.out();
	setlocale(0, "RUS");
	system("PAUSE");
    return 0;
}
