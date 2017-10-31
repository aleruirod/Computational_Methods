#include "CrankNicholsonMethod.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

CrankNicholsonMethod::CrankNicholsonMethod() {}

/*
* Constructor from a vector of double vectors.
*/

CrankNicholsonMethod::CrankNicholsonMethod(std::vector<std::vector<double>> sols) {
	CrankNicholsonMethod::allSolutions = sols;
}

void CrankNicholsonMethod::compute() {

}