#include <iostream>
#include "DuFortFrankelMethod.h"
#include "Output.h"


int main() {
	DuFortFrankelMethod sol = DuFortFrankelMethod();
	sol.compute();
	Output::printVector(sol.getAllSolutions());
}