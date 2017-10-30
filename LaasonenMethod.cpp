#include "LaasonenMethod.h"
#include "Output.h"


LaasonenMethod::LaasonenMethod() {}

LaasonenMethod::LaasonenMethod(std::vector<double> v) {
	LaasonenMethod::setCurrentSolution(v);
}

void LaasonenMethod::addToL(std::vector<double> row) {
	L.resize(posL + 1);
	L[posL] = row;
	posL++;
}

std::vector<std::vector<double>> LaasonenMethod::getL() {
	return L;
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