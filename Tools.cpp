#include "Tools.h"

std::vector<double> Tools::createT0Vector(int n) {

	std::vector<double> t0Vec(n, 100.0);

	t0Vec[0] = 300.0;
	t0Vec[n - 1] = 300.0;

	return t0Vec;

}