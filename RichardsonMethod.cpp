#include "RichardsonMethod.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

RichardsonMethod::RichardsonMethod() {}

/*
* Constructor from a vector of double vectors.
*/

RichardsonMethod::RichardsonMethod(std::vector<std::vector<double>> sols) {
	RichardsonMethod::allSolutions = sols;
}

// COMPUTATION
/**
* Computes and stores the values for the Solution using the Richardson method as well as the forward time, central space method for certain timestep.
*/

void RichardsonMethod::compute() {

	std::vector<double> t0Sol(n + 1);// we start by creating a solution vector for the first timestep which will use the boundary conditions.
	for (int i = 0; i < t0Sol.size(); i++) {
		if (i == 0 || i == n)
			t0Sol[i] = 300.0; //both first and last values will be 300.0.
		else
			t0Sol[i] = 100.0;// all other values will be 100.0.
	}

	addToAllSolutions(t0Sol);// we need to store the values for t = 0.0.

	std::vector<double> t1Sol(n + 1);// We use the forward time, central space method to calculate the second timestep
									 //as we need it to use the Richardson Method. This method is stable in our case
									 // because (D*deltaT)/deltaX^2 = 0.4 (which is <= 0.5 which is the limit for stability)


	for (int i = 0; i < t1Sol.size(); i++) {
		if (i == 0 || i == n)
			t1Sol[i] = 300.0;//as always, first and last values are 300.0.
		else
			t1Sol[i] = t0Sol[i] + ((D*deltaT) / (pow(deltaX, 2)))
			* (t0Sol[i + 1] - 2 * t0Sol[i] + t0Sol[i - 1]);// this is the formula for the forward time central space scheme.
	}

	std::vector<double> compSol(n + 1);
	compSol[0] = 300.0;
	compSol[n] = 300.0;
	std::vector<double> prevSol1 = t1Sol;// we need to keep track of the solutions for the two previous timesteps in order to satisfy the algorithm.
	std::vector<double> prevSol2 = t0Sol;

	for (int j = 1; j < 51; j++) { // we choose 51 as the limit of the loop as we need at least 50 timesteps to get to t = 0.5.

		for (int i = 1; i < compSol.size() - 1; i++) {

			compSol[i] = ((2 * deltaT*D*((prevSol1[i + 1] - 2 * prevSol1[i] + prevSol1[i - 1]) / pow(deltaX, 2))) + prevSol2[i]);
			
		}
		if ((j % 10) == 0)// We store the values for t = 0.1, 0.2,...,0.5 (every 10 timesteps).
			addToAllSolutions(compSol);

		prevSol2 = prevSol1;
		prevSol1 = compSol;
	}
}