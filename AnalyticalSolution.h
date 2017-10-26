#ifndef ANALYTICAL_H
#define ANALYTICAL_H

#include "Solution.h"

class AnalyticalSolution : public Solution {
	public:

		AnalyticalSolution();

		AnalyticalSolution(std::vector<double> v);

		void compute();

	protected:
		const double PI = 3.141592;
};

#endif
