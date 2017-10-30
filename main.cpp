#include <iostream>
#include "DuFortFrankelMethod.h"
#include "RichardsonMethod.h"
#include "AnalyticalSolution.h"
#include "LaasonenMethod.h"
#include "Output.h"


int main() {
	DuFortFrankelMethod duFortFrankelSol = DuFortFrankelMethod();
	duFortFrankelSol.compute();
	Output::printSolution(duFortFrankelSol.getAllSolutions());
	AnalyticalSolution analyt = AnalyticalSolution();
	analyt.compute();
	Output::printSolution(analyt.getAllSolutions());
	RichardsonMethod richardsonSol = RichardsonMethod();
	richardsonSol.compute();
	Output::printSolution(richardsonSol.getAllSolutions());
	LaasonenMethod laasonenSol = LaasonenMethod();
	laasonenSol.compute();
	Output::printSolution(laasonenSol.getL());
}