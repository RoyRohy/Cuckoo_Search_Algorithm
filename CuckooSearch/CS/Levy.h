#ifndef LEVY_H
#define LEVY_H
//#include "Solution.h"
#include <limits>
#include <cstddef>
#include <iostream>
#include <math.h>
//#include "stdafx.h"
//#define M_PI 3.14

class Levy
{
	static bool seeded;
	const double TWO_PI = 2.*M_PI,
    MIN_DOUBLE_LIMIT = std::numeric_limits<double>::min();
	double scaling_factor = 1.;
	double z0, z1, u, v, w, beta, inverse_beta, sigma;
	bool generate;

public:
	Levy(double beta, double sigma);
	Levy() : Levy(1,0) {}; // faux

	double rnd();
	//Levy operator*(double factor);
	//friend Levy operator*(double factor, Levy& levy);

private:
	double normalRnd();
};

#endif // LEVY_H
