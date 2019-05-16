#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

struct complex {
	float real;
	float image;
};

complex operator+ (complex c1, complex c2) {
	complex result;
	result.image = c1.image + c2.image;
	result.real = c1.real + c2.real;
	return result;
}

complex operator- (complex c1, complex c2) {
	complex result;
	result.image = c1.image - c2.image;
	result.real = c1.real - c2.real;
	return result;
}

complex operator* (complex c1, complex c2) {
	complex result;
	result.real = (c1.real * c2.real) - (c1.image * c2.image);
	result.image = (c1.real * c2.image) + (c2.real * c1.image);
	return result;
}

complex operator/ (complex c1, complex c2) {
	complex result;
	result.real = ((c1.real * c2.real) + (c1.image * c2.image))/(c1.real*c1.real + c1.image*c1.image);
	result.image = ((c2.real * c1.image) - (c1.real * c2.image)) / (c1.real * c1.real + c1.image * c1.image);
	return result;
}

bool operator== (complex c1, complex c2) {
	if (c1.real == c2.real && c1.image == c2.image) return true;
	return false;
}

bool operator!= (complex c1, complex c2) {
	if (c1.real == c2.real && c1.image == c2.image) return false;
	return true;
}

std::ostream& operator<< (std::ostream& out, complex c) {
	out << c.real << "+(" << c.image << "i)";
	return out;
}

std::istream& operator>> (std::istream& in, complex& c)	{
	in >> c.real;
	in >> c.image;
	return in;
}

#endif // !COMPLEX_H

