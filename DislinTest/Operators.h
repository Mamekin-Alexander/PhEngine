#pragma once
#include <utility>
#include <Vector>
#include <assert.h>
#include "PhTypedefs.h"
/*Vector operators*/

Vector operator+(const Vector&, const Vector&);

Vector operator*(const Vector&, const double&);

Vector operator*(const double&, const Vector&);

Vector operator-(const Vector&, const Vector&);

double operator*(const Vector&, const Vector&);

double abs(const Vector&);

/*Pair operators*/

Phase operator +(const Phase& , const Phase&);

Phase operator*(const Phase&, const double&);

Phase operator*(const double&, const Phase&);


