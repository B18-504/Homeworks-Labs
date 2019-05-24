#pragma once


class Int
{
public:
	int body;

	Int()
	{}
	Int(int a)
	{
		body = a;
	}

	void in();

	void out();

	void operator=(Int &a)
	{
		body = a.body;
	}
	Int operator+(Int &a)
	{
		return(Int(body + a.body));
	}
	Int operator-(Int &a)
	{
		return(Int(body - a.body));
	}
	Int operator*(Int &a)
	{
		return(Int(body * a.body));
	}
	Int operator/(Int &a)
	{
		return(Int(body / a.body));
	}

	bool operator==(Int&a)
	{
		return(body == a.body);
	}
	bool operator>(Int &a)
	{
		return (body > a.body);
	}
};