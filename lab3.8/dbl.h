#pragma once

class Dbl
{
public:
	double body;

	Dbl()
	{}
	Dbl(double a)
	{
		body = a;
	}

	void in(char **);

	void out(char **);

	bool operator==(Dbl &a)
	{
		return(body == a.body);
	}

	bool operator!=(Dbl &a)
	{
		return(body != a.body);
	}
};