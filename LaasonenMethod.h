#ifndef LAASONEN_H
#define LAASONEN_H

#include "Solution.h"

class LaasonenMethod : public Solution {

public:

	// CONSTRUCTORS
	/**
	* Creates an empty LaasonenMethod object
	* @see LaasonenMethod(Vector<Vector<double>> sols);
	*/

	LaasonenMethod();

	/**
	* Creates an LaasonenMethod object from a vector of double vectors.
	* @see LaasonenMethod();
	* @param sols Vector of double vectors that the new Solution will use.
	*/

	LaasonenMethod(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that the new Solution will use. */);

	void addToT(std::vector<double> row);

	std::vector<std::vector<double>> getT();

	//COMPUTATION
	/**
	* Computes and stores the values for the Solution using this method.
	*/

	void compute();

protected:
	double C = (deltaT*D) / pow(deltaX, 2); //For the Laasonen method, the C coeficient is constant throughout the whole problem.
	double aCoef = -C;
	double bCoef = (2 * C + 1);
	double cCoef = -C;
	int posT = 0;
	std::vector<std::vector<double>> Tmat;
};
#endif