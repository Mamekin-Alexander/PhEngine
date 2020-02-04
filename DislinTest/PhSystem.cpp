#include "PhTypedefs.h"
#include "PhSystem.h"
#include "PhObject.h"
#include "Operators.h"
#include <assert.h>

PhSystem::PhSystem(const double G, const double dt, const int dimension)
{
	m_G = G;
	m_dt = dt;
	m_dimension = dimension;
	m_t = 0;
}
PhSystem::~PhSystem()
{
}

Vector PhSystem::field_strength(const Vector& r, PhObject *o_to_ignore = nullptr)	//o_to_ignore - object, that we don't use in calculation of field strength
{
	Vector res;
	res.resize(m_dimension);
	for (auto& comp : res)
		comp = 0.0;
	for (auto& obj : m_obj)
	{
		Vector r12 = obj.get_r() - r;
		if (&obj!=o_to_ignore)
			res = res + m_G * obj.get_mass() / pow(abs(r12), 3)*r12;
	}
	return res;
}
Phase PhSystem::rhs(const Phase& rv, PhObject* obj = nullptr)
{
	Phase res;
	res.first = rv.second;
	res.second = field_strength(rv.first, obj);
	return res;
}
void PhSystem::move()
{
	/*calculating rk4 coefs, but not changing positions of objects*/
	for (auto& obj : m_obj)
	{
		Phase rv;
		rv.first = obj.get_r();
		rv.second = obj.get_v();
	
		Rk4Coefs coefs;
		coefs.k1 = rhs(rv, &obj);
		coefs.k2 = rhs(rv + m_dt / 2 * coefs.k1, &obj);
		coefs.k3 = rhs(rv + m_dt / 2 * coefs.k2, &obj);
		coefs.k4 = rhs(rv + m_dt * coefs.k3, &obj);

		obj.set_rk4_coefs(coefs);
	}

	for (auto& obj : m_obj)
	{
		Phase rv, newrv;
		Rk4Coefs coefs;
		coefs = obj.get_rk4_coefs();
		rv.first = obj.get_r();
		rv.second = obj.get_v();
		newrv = rv + m_dt / 6 * (coefs.k1 + 2 * coefs.k2 + 2 * coefs.k3 + coefs.k4);
		obj.set_r(newrv.first);
		obj.set_v(newrv.second);
		obj.calc_kin_energy();
	}

	m_t = m_t + m_dt;
}

void PhSystem::add_obj(const PhObject& obj)
{

	m_obj.push_back(obj);
}

/*temporary*/
PhObject PhSystem::get_object(const int& index)
{
	return m_obj.at(index);
}
double PhSystem::get_t()
{
	return m_t;
}