#include "AnalyticalSolution.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

AnalyticalSolution::AnalyticalSolution() {}

/*
* Constructor from a vector of double vectors.
*/

AnalyticalSolution::AnalyticalSolution(std::vector<std::vector<double>> sols) {
	AnalyticalSolution::allSolutions = sols;
}

// COMPUTATION
/**
* Computes and stores the values for the Solution using the Analytical solution.
*/

void AnalyticalSolution::compute() {

	std::vector<double> t0AnSol = Tools::createT0Vector(n + 1); // we start by creating a solution vector for the first timestep which will use the boundary conditions.

	addToAllSolutions(t0AnSol);// we need to store the values for t = 0.0.

	std::vector<double> anSol = Tools::createT0Vector(n + 1);

	for (int j = 1; j < 51; j++) { // we choose 51 as the limit of the loop as we need at least 50 timesteps to get to t = 0.5.

		
		for (int i = 1; i < anSol.size() - 1; i++) {
			double sum = 0.0;
			for (int m = 1; m < 1000; m++) // we need the sum of a big number of elements in order to have a good result so a 1000 will probably be enough.
			{
				sum += exp(-D*pow(((m*PI) / L), 2)*(deltaT*(j))) * ((1 - pow((-1), m)) / (m*PI)) * sin((m*PI*(deltaX*i)) / L);
			}
			anSol[i] = 300 + 2 * (100 - 300) * sum; // we use the sum previously calculated so we can compute the complete analytical solution.
		}
		if ((j % 10) == 0) // We store the values for t = 0.1, 0.2,...,0.5 (every 10 timesteps).
			addToAllSolutions(anSol);
	}
} 