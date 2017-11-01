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

void LaasonenMethod::addToT(std::vector<double> row) {
	Tmat.resize(posT + 1);
	Tmat[posT] = row;
	posT++;
}

std::vector<std::vector<double>> LaasonenMethod::getT() {
	return Tmat;
}

void LaasonenMethod::addToD(double d) {
	Dvec.resize(posD + 1);
	Dvec[posD] = d;
	posD++;
}

std::vector<double> LaasonenMethod::getD() {
	return Dvec;
}

void LaasonenMethod::compute() {

	//std::vector<double> rowT(n - 1, 0.0);

	//for (int i = 0; i < rowT.size(); i++) {
	//	
	//	if (i == 0) {
	//		rowT[i] = -(2*C + 1);
	//		rowT[i + 1] = C;

	//	} else if (i == rowT.size() - 1) {
	//		rowT[i - 1] = C;
	//		rowT[i] = -(2*C + 1);

	//	} else {
	//		rowT[i - 1] = C;
	//		rowT[i] = -(2 * C + 1);
	//		rowT[i + 1] = C;
	//	}

	//	addToT(rowT);
	//	std::fill(rowT.begin(), rowT.end(), 0.0); // we reset the vector to all zeros again
	//	
	//}

	std::vector<double> x0(n - 1, 100.0);
	x0[0] = 300.0;
	x0[n - 2] = 300.0;
	std::vector<double> x(n - 1);
	x[0] = 300.0;
	x[n - 2] = 300.0;

	for (int j = 0; j < 51; j++) {


		if (j == 0) {
			
			for (int i = 0; i < n-2; i++) {

				if (i == 0) {
					d[i] = x0[i] - C*x[0];
					cStar[i] = C / -(2 * C + 1);
					dStar[i] = d[i] / -(2 * C + 1);
				}
				else if (i == n - 3) {
					d[i] = x0[i] - C*x[n - 2];
					cStar[i] = C / (-(2 * C + 1) - cStar[i - 1] * C);
					dStar[i] = (d[i] - dStar[i - 1] * C)/(-(2*C+1) - cStar[i - 1]*C);
				}
				else {
					d[i] = x0[i];
					cStar[i] = C / (-(2 * C + 1) - cStar[i - 1] * C);
					dStar[i] = (d[i] - dStar[i - 1] * C) / (-(2 * C + 1) - cStar[i - 1] * C);
				}

			
			}
			
			for (int k = n-3; k > 0; k--) {
				if (k == n - 3)
					x[n - 3] = dStar[n - 3];
				else
					x[k] = dStar[n - 3] - cStar[k] * x[k + 1];
			}
			
		}

	}
}