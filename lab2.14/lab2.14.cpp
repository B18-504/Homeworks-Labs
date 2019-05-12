#include "stdafx.h"
#include "locale.h"
#include "list.h"
#include "strg.h"
#include "cpx.h"
#include "int.h"
#include "io.h"

#define T Int

void dup(Int &a) //to test map
{
	a.body += a.body;
}

bool pos(Int &a) //where
{
	return(a.body > 0);
}

void sum(Int &a, Int &b) //reduce
{
	a.body += b.body;
}

int main()
{
	setlocale(0, "RUS");
	List<T> a, b;
	int c;
	a.in();
	getloopi(c);
	a.cut(b, c);
	a.out();
	cout << endl;
	b.out();
	cout << endl;
	system("PAUSE");
    return 0;
}

