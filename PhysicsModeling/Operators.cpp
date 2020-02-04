#include "Operators.h"

/*Vector operators*/

Vector operator+(const Vector& a, const Vector& b)
{
	assert(a.size() == b.size() && "Vectors have different length!");
	Vector res;
	for (int i = 0, n = a.size(); i < n; i++)
		res.push_back(a.at(i) + b.at(i));
	return res;
}

Vector operator*(const Vector& v, const double& a)
{
	Vector res;
	for (int i = 0, n = v.size(); i < n; i++)
		res.push_back(v.at(i)*a);
	return res;
}

Vector operator*(const double& t, const Vector& v)
{
	return v * t;
}

Vector operator-(const Vector& a, const Vector& b)
{
	return a + (-1)*b;
}

double operator*(const Vector&a, const Vector& b)
{
	assert(a.size() == b.size() && "Vectors have different length!");
	double res=0;
	for (int i = 0, n = a.size(); i < n; i++)
		res=res+a.at(i)*b.at(i);
	return res;
}

double abs(const Vector& v)
{
	return sqrt(v*v);
}

/*Pair operators*/

Phase operator +(const Phase& a, const Phase& b)
{
	Phase res;
	res.first = a.first + b.first;
	res.second = a.second + b.second;
	return res;
}

Phase operator*(const Phase& p, const double& t)
{
	Phase res;
	res.first = p.first*t;
	res.second = p.second*t;
	return res;
}

Phase operator*(const double& t, const Phase& p)
{
	return p * t;
}