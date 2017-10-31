#ifndef CRANKNICHOLSON_H
#define CRANKNICHOLSON_H

#include "Solution.h"

class CrankNicholsonMethod : public Solution {

public:

	CrankNicholsonMethod();

	CrankNicholsonMethod(std::vector<double> v);

	/**
	* Computes and stores the values for the Solution using this method.
	*/

	void compute();

};
#endif
