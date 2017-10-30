#include "CrankNicholsonMethod.h"

CrankNicholsonMethod::CrankNicholsonMethod() {}

CrankNicholsonMethod::CrankNicholsonMethod(std::vector<double> v) {
	CrankNicholsonMethod::setCurrentSolution(v);
}

void CrankNicholsonMethod::compute() {

}