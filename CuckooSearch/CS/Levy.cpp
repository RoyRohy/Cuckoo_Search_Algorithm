#include "Levy.h"

//#include "stdafx.h"
#include "Levy.h"
#include <limits>
#include <time.h>
#include <math.h>
bool Levy::seeded = false;


Levy::Levy(double beta, double sigma)
{
	if (!seeded) {
		std::srand(static_cast<unsigned int>(time(NULL)));
		seeded = true;
	}

	this->beta = beta;
	this->inverse_beta = 1. / beta;
	this->sigma = sigma;
}




double Levy::normalRnd()
{
	static bool generate;
	generate = !generate;

	//if (!generate)
	//	return z1;

	double u1, u2;

	do {
		u1 = (double)rand() / RAND_MAX;
		u2 = (double)rand() / RAND_MAX;
	} while (u1 <= MIN_DOUBLE_LIMIT);

	if (-log(u1) > 0) {
		z0 = sqrt(-2.0 * log(u1)) * cos(TWO_PI * u2);
	}
	else {
		z0 = 0; // z1 = 0;
	}
	return z0;
}

double Levy::rnd()
{
	u = normalRnd();
	do {
		v = normalRnd();
	} while (v == 0);

	double result = scaling_factor * u * sigma / pow(fabs(v), inverse_beta);
	return result;
}

/*Levy Levy::operator*(double factor)
{
	Levy new_levy(beta, sigma);
	new_levy.scaling_factor = factor * scaling_factor;
	return new_levy;
}

Levy operator*(double factor, Levy& levy)
{
	return levy * factor;
}*/
