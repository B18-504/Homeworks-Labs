#include "stdafx.h"
#include "locale.h"
#include "pasta.h"
#include "tree.h"
#include "cpx.h"
#include "dbl.h"
#include <string>
#include "io.h"

void dup(Dbl &a)
{
	a.body += a.body;
}

int main()
{
	setlocale(0, "RUS");
	Tree<Dbl, 2> a, c;
	char **pi = new char*[4];
	pi[0] = "���� ������\n";
	pi[1] = "��������� ��������� ����?: ";
	pi[2] = "������� �����: ";
	pi[3] = "������ �����: ";
	char **po = new char*[4];
	po[0] = "������\n";
	po[1] = "�����\n";
	po[2] = "\n";
	po[3] = "\n";
	int way[3] = { 0,1,2 };
	a.in(pi, way);
	//Line<Dbl, 2> b;
	//b.set(a, way);
	//b.get(c, way);
	a.map(dup);
	system("PAUSE");
    return 0;
}

