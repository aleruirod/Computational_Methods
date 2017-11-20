#include <iostream>
#include "DuFortFrankelMethod.h"
#include "RichardsonMethod.h"
#include "LaasonenMethod.h"
#include "CrankNicholsonMethod.h"
#include "AnalyticalSolution.h"
#include "Output.h"
#include "Tools.h"


int main() {

	std::cout << "Du Fort Frankel\n";

	DuFortFrankelMethod duFortFrankelSol = DuFortFrankelMethod();
	duFortFrankelSol.compute();
	Output::printSolution(duFortFrankelSol.getAllSolutions());
	//Output::exportSolution(duFortFrankelSol, 0.1, "Du Fort Frankel Method_");

	std::cout << "\n";
	std::cout << "Richardson Method\n";

	RichardsonMethod richardsonSol = RichardsonMethod();
	richardsonSol.compute();
	Output::printSolution(richardsonSol.getAllSolutions());
	//Output::exportSolution(richardsonSol, 0.1, "Richardson Method_");

	std::cout << "\n";
	std::cout << "Laasonen deltaT = 0.01\n";

	LaasonenMethod laasonenSol01 = LaasonenMethod();
	laasonenSol01.compute();
	Output::printSolution(laasonenSol01.getAllSolutions());
	//Output::exportSolution(laasonenSol01, 0.1, "Simple Laasonen Method deltaT = 0.01_");

	std::cout << "\n";
	std::cout << "Crank Nicholson\n";

	CrankNicholsonMethod crankNicholsonSol = CrankNicholsonMethod();
	crankNicholsonSol.compute();
	Output::printSolution(crankNicholsonSol.getAllSolutions());
	//Output::exportSolution(crankNicholsonSol, 0.1, "Crank Nicholson_");

	std::cout << "\n";
	std::cout << "Analytical Solution\n";

	AnalyticalSolution analyt = AnalyticalSolution();
	analyt.compute();
	Output::printSolution(analyt.getAllSolutions());
	//Output::exportSolution(analyt, 0.1, "Analytical Solution_");

	std::cout << "\n";
	std::cout << "Laasonen deltaT = 0.025\n";

	LaasonenMethod laasonenSol025 = LaasonenMethod();
	laasonenSol025.setDeltaT(0.025);
	laasonenSol025.compute();
	Output::printSolution(laasonenSol025.getAllSolutions());
	//Output::exportSolution(laasonenSol025, 0.1, "Simple Laasonen Method deltaT = 0.025_");

	std::cout << "\n";
	std::cout << "Laasonen deltaT = 0.05\n";

	LaasonenMethod laasonenSol05 = LaasonenMethod();
	laasonenSol05.setDeltaT(0.05);
	laasonenSol05.compute();
	Output::printSolution(laasonenSol05.getAllSolutions());
	//Output::exportSolution(laasonenSol05, 0.1, "Simple Laasonen Method deltaT = 0.05_");

	std::cout << "\n";
	std::cout << "Laasonen deltaT = 0.1\n";

	LaasonenMethod laasonenSol1 = LaasonenMethod();
	laasonenSol1.setDeltaT(0.1);
	laasonenSol1.compute();
	Output::printSolution(laasonenSol1.getAllSolutions());
	//Output::exportSolution(laasonenSol1, 0.1, "Simple Laasonen Method deltaT = 0.1_");

	std::cout << "\n";
	std::cout << "TWO NORM VALUES:\n";

	std::cout << "\n";
	std::cout << "Du Fort Frankel \n";

	std::vector<double> dufort = Tools::twoNorm(analyt, duFortFrankelSol);

	Output::printVector(dufort);

	std::cout << "\n";
	std::cout << "Richardson \n";

	std::vector<double> rich = Tools::twoNorm(analyt, richardsonSol);

	Output::printVector(rich);

	std::cout << "\n";
	std::cout << "Simple Laasonen \n";

	std::vector<double> las = Tools::twoNorm(analyt, laasonenSol01);

	Output::printVector(las);

	std::cout << "\n";
	std::cout << "Crank Nicholson \n";

	std::vector<double> crank = Tools::twoNorm(analyt, crankNicholsonSol);

	Output::printVector(crank);


}