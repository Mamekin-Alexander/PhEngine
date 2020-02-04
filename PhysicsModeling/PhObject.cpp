#include "PhObject.h"
#include "Operators.h"


PhObject::PhObject(const Vector& r0, const Vector& v0, const double& mass)
{
	m_r = r0;
	m_v = v0;
	m_mass = mass;
	calc_kin_energy();
}

PhObject::~PhObject()
{
}

/*Getters and setters*/
Vector PhObject::get_r()
{
	return m_r;
}
Vector PhObject::get_v() {
	return m_v;
}
double PhObject::get_mass() {
	return m_mass;
}
double PhObject::get_kin_energy()
{
	return m_kin_energy;
}
Rk4Coefs PhObject::get_rk4_coefs()
{
	return m_rk4_coefs;
}

void PhObject::set_r(const Vector& r)
{
	m_r = r;
}
void PhObject::set_v(const Vector& v)
{
	m_v = v;
}
void PhObject::set_rk4_coefs(const Rk4Coefs& coefs)
{
	m_rk4_coefs = coefs;
}
void PhObject::calc_kin_energy()
{
	m_kin_energy = m_mass * sqrt(m_v*m_v) / 2;
}
