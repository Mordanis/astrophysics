/* +++++++++++++++++++++++++++++++++++++++++++++++++++++
File written by John Van Dyke in Spring 2015
function will compute the probability that a
single particle in an ideal gas will have a certain 
velocity given a temperature in kelvin and a mass in amu
+++++++++++++++++++++++++++++++++++++++++++++++++++++ */

#include "thermo_constants.h"

float boltz_dist(float temp,float mass, float velocity)
{
	float factor1, factor2, factor3;
	float probability;

	factor1 = pow(mass/(2*pi*k_boltz*temp),1.5)
	factor2 = 4 * pi * velocity * velocity
	factor3 = exp(-m*velocity*velocity/(2*k_boltz*temp));
	probability = factor1 * factor2 * factor3;

	return probability;
}
