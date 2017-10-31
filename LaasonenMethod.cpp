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

void LaasonenMethod::addToL(std::vector<double> row) {
	Lmat.resize(posL + 1);
	Lmat[posL] = row;
	posL++;
}

std::vector<std::vector<double>> LaasonenMethod::getL() {
	return Lmat;
}


void LaasonenMethod::compute() {

	std::vector<double> rowL(n - 1, 0.0);

	for (int i = 0; i < rowL.size(); i++) {
		
		if (i == 0) {
			rowL[i] = -(2*C + 1);
			rowL[i + 1] = C;

		} else if (i == rowL.size() - 1) {
			rowL[i - 1] = C;
			rowL[i] = -(2*C + 1);

		} else {
			rowL[i - 1] = C;
			rowL[i] = -(2 * C + 1);
			rowL[i + 1] = C;
		}

		addToL(rowL);
		std::fill(rowL.begin(), rowL.end(), 0.0); // we reset the vector to all zeros again
		
	}

}