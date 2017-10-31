#ifndef RICHARDSON_H
#define RICHARDSON_H

#include "Solution.h"

/**
* The RichardsonMethod is an explicit and unconditionally unstable method.
* \n This method will produce a solution with an error increasing in time.
*/


class RichardsonMethod : public Solution {

public:

	// CONSTRUCTORS
	/**
	* Creates an empty RichardsonMethod object
	* @see RichardsonMethod(Vector<Vector<double>> sols);
	*/

	RichardsonMethod();

	/**
	* Creates an RichardsonMethod object from a vector of double vectors.
	* @see RichardsonMethod();
	* @param sols  Vector of double vectors that the new Solution will use.
	*/

	RichardsonMethod(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that the new Solution will use. */);

	//COMPUTATION
	/**
	* Computes and stores the values for the Solution using this method.
	*/

	void compute();
};
#endif