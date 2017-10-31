#include "DuFortFrankelMethod.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

DuFortFrankelMethod::DuFortFrankelMethod() {}

/*
* Constructor from a vector of double vectors.
*/

DuFortFrankelMethod::DuFortFrankelMethod(std::vector<std::vector<double>> sols) {
	DuFortFrankelMethod::allSolutions = sols;
}

// COMPUTATION
/**
* Computes and stores the values for the Solution using the Du Fort Frankel method as well as the forward time, central space method for certain timestep.
*/

void DuFortFrankelMethod::compute() {

	std::vector<double> t0Sol(n+1); // we start by creating a solution vector for the first timestep which will use the boundary conditions.
	for (int i = 0; i < t0Sol.size(); i++) {
		if (i == 0 || i == n)
			t0Sol[i] = 300.0; //both first and last values will be 300.0.
		else
			t0Sol[i] = 100.0;// all other values will be 100.0.
	}

	std::vector<double> t1Sol(n+1);// We use the forward time, central space method to calculate the second timestep
								// as we need it to use the Du Fort Frankel Method. This method is stable in our case
								// because (D*deltaT)/deltaX^2 = 0.4 (which is <= 0.5 which is the limit for stability)

	addToAllSolutions(t0Sol);// we need to store the values for t = 0.0.

	for (int i = 0; i < t1Sol.size(); i++) {
		if (i == 0 || i == n)
			t1Sol[i] = 300.0; //as always, first and last values are 300.0.
		else
			t1Sol[i] = t0Sol[i] + ((D*deltaT) / (pow(deltaX, 2))) // this is the formula for the forward time central space scheme.
				* (t0Sol[i + 1] - 2 * t0Sol[i] + t0Sol[i - 1]);
	}
	
	for (int j = 0; j < 51; j++) { // we choose 51 as the limit of the loop as we need at least 50 timesteps to get to t = 0.5.
		
		std::vector<double> compSol(n+1);
		compSol[0] = 300.0;
		compSol[n] = 300.0;
		for (int i = 1; i < compSol.size() - 1; i++) {

			if (j == 0) {// for the first application of the Du Fort Frankel Method we need t0 and t1 (previously calculated).
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * t0Sol[i] 
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (t1Sol[i + 1] + t1Sol[i - 1])))
					/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
			}
			else if (j == 1) {// for the second application we just need t1 and the previous value calculated by this method.
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * t1Sol[i]
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (getAllSolutions()[allSolPos-1][i + 1] + getAllSolutions()[allSolPos-1][i - 1])))
					/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
			}
			else // from now on we can just use values calculated by the Du Fort Frankel Method.
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * getAllSolutions()[allSolPos-2][i]
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (getAllSolutions()[allSolPos-1][i + 1] + getAllSolutions()[allSolPos-1][i - 1])))
				/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
		}
		if ((j % 10) == 0) // We store the values for t = 0.1, 0.2,...,0.5 (every 10 timesteps).
			addToAllSolutions(compSol);
	}


}

