#pragma once

#include <math.h>

class Cpx
{
public:

	double re, im;

	Cpx()
	{}
	Cpx(double r, double i = 0)
	{
		re = r;
		im = i;
	}



	void operator=(double a)
	{
		re = a;
		im = 0;
	}
	void operator=(Cpx &a)
	{
		re = a.re;
		im = a.im;
	}

	double mod()
	{
		return sqrt((re*re + im*im));
	}
	
	Cpx conj() //сопряжённое
	{
		return Cpx(re, -im);
	}

	Cpx inv() //обратное
	{
		return conj() / (re*re + im*im);
	}



	Cpx operator+(double a)
	{
		return Cpx(re + a, im);
	}
	Cpx operator+(Cpx &a)
	{
		return Cpx(re + a.re, im + a.im);
	}

	Cpx operator-(double a)
	{
		return Cpx(re - a, im);
	}
	Cpx operator-(Cpx &a)
	{
		return Cpx(re - a.re, im - a.im);
	}

	Cpx operator*(double a)
	{
		return Cpx(re * a, im * a);
	}
	Cpx operator*(Cpx &a)
	{
		return Cpx(re*a.re - im*a.im, re*a.im + im*a.re);
	}
	
	Cpx operator/(double a)
	{
		return Cpx(re / a, im / a);
	}
	Cpx operator/(Cpx &a)
	{
		return Cpx(*this*a.inv());
	}
};

