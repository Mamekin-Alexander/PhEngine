#pragma once
#include <vector>
#include <fstream>
#include "PhTypedefs.h"
class PhObject;
class PhSystem
{
public:
	PhSystem(const double, const double, const int);
	~PhSystem();

	double potential(const Vector&);
	Vector field_strength(const Vector&, PhObject*);

	void move();
	void add_obj(const PhObject&);
	void print_objs(std::ofstream&);

	/*temporary*/
	PhObject get_object(const int&);
	double get_t();
private:
	std::vector<PhObject> m_obj;
	Phase rhs(const Phase&, PhObject*);
	double m_G, m_dt, m_t;
	int m_dimension;
};

