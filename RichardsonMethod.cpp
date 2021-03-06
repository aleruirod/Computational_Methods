#include "RichardsonMethod.h"
#include "Tools.h"


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

	std::vector<double> t0Sol = Tools::createT0Vector(n + 1);// we start by creating a solution vector for the first timestep which will follow the boundary conditions.

	addToAllSolutions(t0Sol);// we need to store the values for t = 0.0.

	std::vector<double> t1Sol = Tools::createT0Vector(n + 1);// We use the forward time, central space method to calculate the second timestep
									 //as we need it to use the Richardson Method. This method is stable in our case
									 // because (D*deltaT)/deltaX^2 = 0.4 (which is <= 0.5 which is the limit for stability)


	for (size_t i = 0; i < t1Sol.size(); i++) {
		if (i == 0 || i == n)
			t1Sol[i] = 300.0;//as always, first and last values are 300.0.
		else
			t1Sol[i] = t0Sol[i] + ((D*deltaT) / (pow(deltaX, 2)))
			* (t0Sol[i + 1] - 2 * t0Sol[i] + t0Sol[i - 1]);// this is the formula for the forward time central space scheme.
	}

	std::vector<double> compSol = Tools::createT0Vector(n + 1);
	
	std::vector<double> prevSol1 = t1Sol;// we need to keep track of the solutions for the two previous timesteps in order to satisfy the algorithm.
	std::vector<double> prevSol2 = t0Sol;

	for (int j = 1; j < (0.5 / deltaT) + 1; j++) {// the limit for this loop is the number of timesteps needed to get to t = 0.5.

		for (size_t i = 1; i < compSol.size() - 1; i++) {

			compSol[i] = ((2 * deltaT*D*((prevSol1[i + 1] - 2 * prevSol1[i] + prevSol1[i - 1]) / pow(deltaX, 2))) + prevSol2[i]);
			
		}
		if ((j % (int)(0.1 / deltaT)) == 0)// We store the values for t = 0.1, 0.2,...,0.5.
			addToAllSolutions(compSol);

		prevSol2 = prevSol1;
		prevSol1 = compSol;
	}
}