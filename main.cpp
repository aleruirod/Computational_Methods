#include <iostream>
#include "DuFortFrankelMethod.h"
#include "AnalyticalSolution.h"
#include "Output.h"


int main() {
	DuFortFrankelMethod sol = DuFortFrankelMethod();
	sol.compute();
	Output::printSolution(sol.getAllSolutions());
	AnalyticalSolution analyt = AnalyticalSolution();
	analyt.compute();
	Output::printSolution(analyt.getAllSolutions());
}