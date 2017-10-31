#ifndef CRANKNICHOLSON_H
#define CRANKNICHOLSON_H

#include "Solution.h"

class CrankNicholsonMethod : public Solution {

public:

	// CONSTRUCTORS
	/**
	* Creates an empty CrankNicholsonMethod object
	* @see CrankNicholsonMethod(Vector<Vector<double>> sols);
	*/

	CrankNicholsonMethod();

	/**
	* Creates an CrankNicholsonMethod object from a vector of double vectors.
	* @see CrankNicholsonMethod();
	* @param sols Vector of double vectors that the new Solution will use.
	*/

	CrankNicholsonMethod(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that the new Solution will use. */);

	//COMPUTATION
	/**
	* Computes and stores the values for the Solution using this method.
	*/

	void compute();

};
#endif
