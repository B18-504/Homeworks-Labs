#pragma once

#include <string>

using namespace std;

class Strg
{
public:
	string body;

	Strg()
	{}
	Strg(Strg &a)
	{
		body = a.body;
	}

	bool operator==(Strg&a)
	{
		return(body == a.body);
	}
	bool operator>(Strg &a)
	{
		return (body > a.body);
	}

	void concat(Strg &a)
	{
		body += a.body;
	}

	void in();

	void out();
};