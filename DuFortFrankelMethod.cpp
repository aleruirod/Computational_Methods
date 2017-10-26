#include "DuFortFrankelMethod.h"

DuFortFrankelMethod::DuFortFrankelMethod() {}

DuFortFrankelMethod::DuFortFrankelMethod(std::vector<double> v) {
	DuFortFrankelMethod::setCurrentSolution(v);
}

void DuFortFrankelMethod::compute() {
	std::vector<double> t0Sol(n+1);
	for (int i = 0; i < (n+1); i++) {
		if (i == 0 || i == n)
			t0Sol[i] = 300.0;
		else
			t0Sol[i] = 100.0;
	}

	std::vector<double> t1Sol(n+1);// We use the forward time, central space method to calculate the second timestep
								//as we need it to use the DuFortFrankelMEthod. This method is stable in our case
								// because (D*deltaT)/deltaX^2 = 0.4 (which is <= 0.5 which is the limit for stability)


	for (int i = 0; i < (n + 1); i++) {
		if (i == 0 || i == n)
			t1Sol[i] = 300.0;
		else
			t1Sol[i] = t0Sol[i] + ((D*deltaT) / (pow(deltaX, 2)))
				* (t0Sol[i + 1] - 2 * t0Sol[i] + t0Sol[i - 1]);
	}

	addToAllSolutions(t0Sol);
	
	for (int j = 0; j < 51; j++) {
		
		std::vector<double> compSol(n+1);
		compSol[0] = 300.0;
		compSol[n] = 300.0;
		for (int i = 1; i < compSol.size() - 1; i++) {
			if (j == 0) {
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * t0Sol[i]
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (t1Sol[i + 1] + t1Sol[i - 1])))
					/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
			}
			else if (j == 1) {
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * t1Sol[i]
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (getAllSolutions()[allSolPos-1][i + 1] + getAllSolutions()[allSolPos-1][i - 1])))
					/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
			}
			else
				compSol[i] = ((1 - ((2 * D*deltaT) / (pow(deltaX, 2)))) * getAllSolutions()[allSolPos-2][i]
					+ (((2 * D*deltaT) / (pow(deltaX, 2))) * (getAllSolutions()[allSolPos-1][i + 1] + getAllSolutions()[allSolPos-1][i - 1])))
				/ (1 + ((2 * D*deltaT) / (pow(deltaX, 2))));
		}

		addToAllSolutions(compSol);
	}


}

