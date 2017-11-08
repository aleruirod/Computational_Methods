#include <iostream>
#include "DuFortFrankelMethod.h"
#include "RichardsonMethod.h"
#include "LaasonenMethod.h"
#include "CrankNicholsonMethod.h"
#include "AnalyticalSolution.h"
#include "Output.h"


int main() {

	DuFortFrankelMethod duFortFrankelSol = DuFortFrankelMethod();
	duFortFrankelSol.compute();
	Output::printSolution(duFortFrankelSol.getAllSolutions());
	//Output::exportSolution(duFortFrankelSol, 0.1, "Du Fort Frankel Method_");

	std::cout << "\n";

	RichardsonMethod richardsonSol = RichardsonMethod();
	richardsonSol.compute();
	Output::printSolution(richardsonSol.getAllSolutions());
	//Output::exportSolution(richardsonSol, 0.1, "Richardson Method_");

	std::cout << "\n";

	LaasonenMethod laasonenSol = LaasonenMethod();
	laasonenSol.compute();
	Output::printSolution(laasonenSol.getAllSolutions());
	//Output::exportSolution(laasonenSol, 0.1, "Simple Laasonen Method_");

	std::cout << "\n";

	CrankNicholsonMethod crankNicholsonSol = CrankNicholsonMethod();
	crankNicholsonSol.compute();
	Output::printSolution(crankNicholsonSol.getAllSolutions());
	//Output::exportSolution(crankNicholsonSol, 0.1, "Crank Nicholson_");

	std::cout << "\n";

	AnalyticalSolution analyt = AnalyticalSolution();
	analyt.compute();
	Output::printSolution(analyt.getAllSolutions());
	//Output::exportSolution(analyt, 0.1, "Analytical Solution_");

}