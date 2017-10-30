#ifndef RICHARDSON_H
#define RICHARDSON_H

#include "Solution.h"

class RichardsonMethod : public Solution {

public:

	RichardsonMethod();

	RichardsonMethod(std::vector<double> v);

	void compute();
};
#endif