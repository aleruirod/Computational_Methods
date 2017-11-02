#include "LaasonenMethod.h"
#include <iostream>

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

void LaasonenMethod::addToT(std::vector<double> row) {
	Tmat.resize(posT + 1);
	Tmat[posT] = row;
	posT++;
}

std::vector<std::vector<double>> LaasonenMethod::getT() {
	return Tmat;
}

void LaasonenMethod::compute() {

	std::vector<double> rowT(n - 1, 0.0);

	for (int i = 0; i < rowT.size(); i++) {
		
		if (i == 0) {
			rowT[i] = bCoef;
			rowT[i + 1] = cCoef;

		} else if (i == rowT.size() - 1) {
			rowT[i - 1] = aCoef;
			rowT[i] = bCoef;

		} else {
			rowT[i - 1] = aCoef;
			rowT[i] = bCoef;
			rowT[i + 1] = cCoef;
		}

		addToT(rowT);
		std::fill(rowT.begin(), rowT.end(), 0.0); // we reset the vector to all zeros again
		
	}

	std::vector<double> previousX(n + 1, 100.0);
	previousX[0] = 300.0;
	previousX[n] = 300.0;
	std::vector<double> x(n + 1,100.0);
	x[0] = 300.0;
	x[n] = 300.0;
	addToAllSolutions(x);
	std::vector<double> d(n - 1);
	std::vector<double> cStar(n - 1);
	std::vector<double> dStar(n - 1);

	for (int j = 1; j < 51; j++) {
			
		for (int i = 0; i < n - 1; i++) {

			if (i == 0) {

				d[i] = previousX[i + 1] - aCoef*x[0];
				cStar[i] = cCoef / bCoef;
				dStar[i] = d[i] / bCoef;

			} else if (i == n - 2) {

				d[i] = previousX[i + 1] - cCoef*x[n];
				cStar[i] = 0 / (bCoef - cStar[i - 1] * aCoef);
				dStar[i] = (d[i] - dStar[i - 1] * aCoef) / (bCoef - cStar[i - 1] * aCoef);

			} else {

				d[i] = previousX[i + 1];
				cStar[i] = cCoef / (bCoef - cStar[i - 1] * aCoef);
				dStar[i] = (d[i] - dStar[i - 1] * aCoef) / (bCoef - cStar[i - 1] * aCoef);
			}
			
		}
			
		for (int k = n - 1; k > 0; k--) {
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