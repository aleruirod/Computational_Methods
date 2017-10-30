#ifndef CRANKNICHOLSON_H
#define CRANKNICHOLSON_H

#include "Solution.h"

class CrankNicholsonMethod : public Solution {

public:

	CrankNicholsonMethod();

	CrankNicholsonMethod(std::vector<double> v);

	void compute();

};
#endif
