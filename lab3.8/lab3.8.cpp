#include "stdafx.h"
#include "locale.h"
#include "pasta.h"
#include "int.h"
#include "tree.h"
#include "cpx.h"
#include "dbl.h"
#include "io.h"

void dup(Dbl &a)
{
	a.body += a.body;
}

bool pos(Dbl &a)
{
	return (a.body > 0);
}

int main()
{
	setlocale(0, "RUS");
	Tree<Dbl, 2> a, b;
	List<Int> c;
	char **pi = new char*[4];
	pi[0] = "Ввод дерева\n";
	pi[1] = "Создать следующий узел?(у/n): ";
	pi[2] = "Введите число: ";
	pi[3] = "Мнимая часть: ";
	char **po = new char*[4];
	po[0] = "Дерево\n";
	po[1] = "Новый узел\n";
	po[2] = "Тупик\n";
	po[3] = "\n";
	char **p = new char*[2];
	p[0] = "Путь\n";
	p[1] = "\n";
	int way[3] = { 0,1,2 };
	a.in(pi, way);
	b.in(pi, way);
	a.find(b, c);
	c.out(p);
	system("PAUSE");
    return 0;
}

