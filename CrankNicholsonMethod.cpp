#include "CrankNicholsonMethod.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

CrankNicholsonMethod::CrankNicholsonMethod() {}

/*
* Constructor from a vector of double vectors.
*/

CrankNicholsonMethod::CrankNicholsonMethod(std::vector<std::vector<double>> sols) {
	CrankNicholsonMethod::allSolutions = sols;
}

void CrankNicholsonMethod::compute() {

	std::vector<double> previousX(n + 1, 100.0); // we need to keep track for the solutions of the previous timestep to satisfy the Thomas algorithm.
	previousX[0] = 300.0;
	previousX[n] = 300.0;
	std::vector<double> x(n + 1, 100.0);
	x[0] = 300.0;
	x[n] = 300.0;
	addToAllSolutions(x);
	std::vector<double> d(n - 1); // this is the d vector used in the Thomas algorithm
	std::vector<double> cStar(n - 1);// These are the c* and d* vectors used during the forward and backward substitution phases of the algorithm.
	std::vector<double> dStar(n - 1);

	for (int j = 1; j < 51; j++) { // we set the limit of the number of timestep calculations to 51 as we need to reach t = 0.5 (50 timesteps).

		for (int i = 0; i < n - 1; i++) {

			if (i == 0) {// first value of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = -aCoef*previousX[i] + (1 - C)*previousX[i + 1] + -cCoef*previousX[i + 2] - aCoef*x[0];
				cStar[i] = cCoef / bCoef;
				dStar[i] = d[i] / bCoef;

			}
			else if (i == n - 2) {// last value of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = -aCoef*previousX[i] + (1 - C)*previousX[i + 1] + -cCoef*previousX[i + 2] - cCoef*x[n];
				cStar[i] = 0 / (bCoef - cStar[i - 1] * aCoef);
				dStar[i] = (d[i] - dStar[i - 1] * aCoef) / (bCoef - cStar[i - 1] * aCoef);

			}
			else {//intermediate values of the d vector calculation and simultaneously the forward substitution phase of the algorithm.

				d[i] = -aCoef*previousX[i] + (1 - C)*previousX[i + 1] + -cCoef*previousX[i + 2];
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

		if ((j % 10) == 0) // We store the values for t = 0.1, 0.2,...,0.5 (every 10 timesteps).
			addToAllSolutions(x);

		previousX = x;
	}
}