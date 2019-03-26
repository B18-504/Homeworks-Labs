#pragma once

#define FLUSH fseek(stdin, 0, SEEK_END)
#define ULLI unsigned long long int
#define MULLI ULLI(-1)

#include <iostream>

using namespace std;


void getd(double &a, bool &err) // ������� ������� �� ������� �����, ���� ��� �� ��� - ����������� (�� ������������, � ����, ����������!)
{
	char buff;
	bool first = 1, point = 0, finish = 0;
	double mul = 1;
	a = 0;
	err = 0;
	finish = 0;
	do
	{
		if (point)
		{
			mul /= 10;
		}
		buff = getchar();
		if ((first) * (buff == '-'))
		{
			mul = -1;
			first = 0;
		}
		else if ((!point) * (buff == '.'))
		{
			point = 1;
			first = 0;
		}
		else if (isdigit(buff))
		{
			first = 0;
			if (!point)
				a *= 10;
			a += mul * (buff - 48);
		}
		else if ((buff == '\n')*(!first))
		{
			finish = 1;
		}
		else
		{
			err = 1;
		}
	} while ((!err) * (!finish));
	FLUSH;
}

void getloopd(double &a) // ���������-����
{
	bool err = 1;
	while (err)
	{
		getd(a, err);
	}
}

void reqd(double &a, char *request, bool &err) // �� ��, ��� � get, �� � ��������� ������� �� �������
{
	cout << request;
	getd(a, err);
}

void reqloopd(double &a, char *request) // ���������-�������
{
	bool err = 1;
	while (err)
	{
		reqd(a, request, err);
	}
}



void getch(char &a, char *valid, bool &err) // � ����� VALID ������ ������ ����!
{
	err = 1;
	char *p = valid;
	a = getchar();
	while ((*p)*(err))
	{
		if (*p == a)
		{
			err = 0;
		}
		p++;
	}
	FLUSH;
}

void getloopch(char &a, char *valid)
{
	bool err = 1;
	while (err)
	{
		getch(a, valid, err);
	}
}

void reqch(char &a, char *valid, char *request, bool &err)
{
	cout << request;
	getch(a, valid, err);
}

void reqloopch(char &a, char *valid, char *request)
{
	bool err = 1;
	while (err)
	{
		reqch(a, valid, request, err);
	}
}



void getulli(ULLI &a, bool &err) //� ��������� �����, � �.�. �� ������� (�����������!)
{
	char buff;
	bool finish = 0, first = 1;
	a = 0;
	err = 0;
	do 
	{
		buff = getchar();
		if (isdigit(buff))
		{
			first = 0;
			if ((a * 10) >= a) //� ��� �� ������
			{
				a *= 10;
				if (ULLI(MULLI - buff + 48) >= a)
				{
					a += buff - 48;
				}
				else
				{
					err = 1;
				}
			}
			else
			{
				err = 1;
			}
		}
		else if ((buff == '\n')*(!first))
		{
			finish = 1;
		}
		else
		{
			err = 1;
		}
	} while ((!finish)*(!err));
	FLUSH;
}

void getloopulli(ULLI &a)
{
	bool err = 1;
	while (err)
	{
		getulli(a, err);
	}
}

void requlli(ULLI &a, char *request, bool &err)
{
	cout << request;
	getulli(a, err);
}

void reqloopulli(ULLI &a, char *request)
{
	bool err = 1;
	while (err)
	{
		requlli(a, request, err);
	}
}