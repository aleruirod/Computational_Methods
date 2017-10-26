#include "AnalyticalSolution.h"
#include <math.h>

AnalyticalSolution::AnalyticalSolution() {}

AnalyticalSolution::AnalyticalSolution(std::vector<double> v) {
	AnalyticalSolution::setCurrentSolution(v);
}

void AnalyticalSolution::compute() {
	std::vector<double> t0aAnSol(n+1);

	t0aAnSol[0] = 300.0;
	t0aAnSol[n] = 300.0;

	for (int i = 1; i < t0aAnSol.size() - 1; i++)
	{
		t0aAnSol[i] = 100.0;
	}

	addToAllSolutions(t0aAnSol);

	for (int j = 1; j < 51; j++) {

		std::vector<double> anSol(n+1);
		anSol[0] = 300.0;
		anSol[n] = 300.0;
		for (int i = 1; i < anSol.size() - 1; i++) {
			double sum = 0.0;
			for (int m = 1; m < 1000; m++)
			{
				sum += exp(-D*pow(((m*PI) / L), 2)*(deltaT*(j))) * ((1 - pow((-1), m)) / (m*PI)) * sin((m*PI*(deltaX*i)) / L);
			}
			anSol[i] = 300 + 2 * (100 - 300) * sum;
		}
		if ((j % 10) == 0)
			addToAllSolutions(anSol);
	}
} 