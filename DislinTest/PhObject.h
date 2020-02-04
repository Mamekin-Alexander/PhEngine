#pragma once
#include "PhTypedefs.h"
class PhObject
{
public:
	PhObject(const Vector&, const Vector&, const double&);
	~PhObject();

	Vector get_r();
	Vector get_v();
	double get_mass();
	double get_kin_energy();
	Rk4Coefs get_rk4_coefs();
	
	void set_r(const Vector&);
	void set_v(const Vector&);
	void set_rk4_coefs(const Rk4Coefs&);
	void calc_kin_energy();
private:
	double m_mass, m_kin_energy;
	Vector m_r, m_v;
	Rk4Coefs m_rk4_coefs;
};

