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
	std::cout << "\n";
	RichardsonMethod richardsonSol = RichardsonMethod();
	richardsonSol.compute();
	Output::printSolution(richardsonSol.getAllSolutions());
	std::cout << "\n";
	LaasonenMethod laasonenSol = LaasonenMethod();
	laasonenSol.compute();
	Output::printSolution(laasonenSol.getAllSolutions());
	std::cout << "\n";
	CrankNicholsonMethod crankNicholsonSol = CrankNicholsonMethod();
	crankNicholsonSol.compute();
	Output::printSolution(crankNicholsonSol.getAllSolutions());
	std::cout << "\n";
	AnalyticalSolution analyt = AnalyticalSolution();
	analyt.compute();
	Output::printSolution(analyt.getAllSolutions());
}