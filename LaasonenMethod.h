#ifndef LAASONEN_H
#define LAASONEN_H

#include "Solution.h"

class LaasonenMethod : public Solution {

public:

	LaasonenMethod();

	LaasonenMethod(std::vector<double> v);

	void addToL(std::vector<double> row);

	std::vector<std::vector<double>> getL();

	/**
	* Computes and stores the values for the Solution using this method.
	*/

	void compute();

protected:
	double C = (deltaT*D) / pow(deltaX, 2); //For the Laasonen method, the C coeficient is constant throughout the whole problem.
	int posL = 0;
	std::vector<std::vector<double>> L;
};
#endif