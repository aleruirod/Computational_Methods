#include "LaasonenMethod.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

LaasonenMethod::LaasonenMethod() {}

/*
* Constructor from a vector of double vectors.
*/

LaasonenMethod::LaasonenMethod(std::vector<std::vector<double>> sols) {
	LaasonenMethod::allSolutions = sols;
}

// COMPUTATION
/**
* Computes and stores the values for the Solution using the Simple Implicit Laasonen method, for this, we will carry out the Thomas Algorithm.
*/

void LaasonenMethod::compute() {

	std::vector<double> previousX = Tools::createT0Vector(n + 1); // we need to keep track for the solutions of the previous timestep to satisfy the Thomas algorithm.
	std::vector<double> x = Tools::createT0Vector(n + 1);
	addToAllSolutions(x);

	std::vector<double> d(n - 1); // this is the d vector used in the Thomas algorithm
	std::vector<double> cStar(n - 1);// These are the c* and d* vectors used during the forward and backward substitution phases of the algorithm.
	std::vector<double> dStar(n - 1);

	for (int j = 1; j < (0.5/deltaT) + 1; j++) {// the limit for this loop is the number of timesteps needed to get to t = 0.5.
			
		for (int i = 0; i < n - 1; i++) {

			if (i == 0) {// first value of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = previousX[i + 1] - aCoef*x[0];
				cStar[i] = cCoef / bCoef;
				dStar[i] = d[i] / bCoef;

			} else if (i == n - 2) {// last value of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = previousX[i + 1] - cCoef*x[n];
				cStar[i] = 0 / (bCoef - cStar[i - 1] * aCoef);
				dStar[i] = (d[i] - dStar[i - 1] * aCoef) / (bCoef - cStar[i - 1] * aCoef);

			} else {//intermediate values of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = previousX[i + 1];
				cStar[i] = cCoef / (bCoef - cStar[i - 1] * aCoef);
				dStar[i] = (d[i] - dStar[i - 1] * aCoef) / (bCoef - cStar[i - 1] * aCoef);
			}
			
		}
			
		for (int k = n - 1; k > 0; k--) { // backwards substitution phase to get the final values of the solution for the current timestep.
			if (k == n - 1)
				x[k] = dStar[k - 1];
			else
				x[k] = dStar[k - 1] - cStar[k - 1] * x[k + 1];
		}

		if ((j % (int) (0.1/deltaT)) == 0) // We store the values for t = 0.1, 0.2,...,0.5.
			addToAllSolutions(x);

		previousX = x;
	}
}