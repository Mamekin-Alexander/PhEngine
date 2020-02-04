#pragma once
#include <utility>
#include <vector>
typedef std::vector<double> Vector;
typedef std::pair<Vector, Vector>Phase;
struct Rk4Coefs
{
	Phase k1, k2, k3, k4;
};