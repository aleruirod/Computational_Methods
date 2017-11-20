#include "Tools.h"

std::vector<double> Tools::createT0Vector(int n) {

	std::vector<double> t0Vec(n, 100.0);

	t0Vec[0] = 300.0;
	t0Vec[n - 1] = 300.0;

	return t0Vec;

}

std::vector<double> Tools::twoNorm(Solution analytSol, Solution sol) {

	std::vector<std::vector<double>> allAnalyticalSols = analytSol.getAllSolutions();
	std::vector<std::vector<double>> allSolutionsToCompare = sol.getAllSolutions();

	std::vector<double> twoNormResult(allAnalyticalSols.size());

	for (size_t i = 0; i < allAnalyticalSols.size(); i++) {

		std::vector<double> analyticalSoln = allAnalyticalSols[i];
		std::vector<double> solutionToCompare = allSolutionsToCompare[i];

		double sum = 0.0;

		for (size_t j = 0; j < analyticalSoln.size(); j++) {

			sum += (solutionToCompare[j] - analyticalSoln[j]) * (solutionToCompare[j] - analyticalSoln[j]);
		}

		twoNormResult[i] = sqrt(sum);

	}
	
	return twoNormResult;
}