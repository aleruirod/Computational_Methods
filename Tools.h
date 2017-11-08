#ifndef TOOLS_H
#define TOOLS_H

#include <vector>

/**
* The Tools class contains functions to support the computation
* \n and processing of results.
*/

class Tools {

public:

	/**
	* Creates a vector following the boundary conditions of the problem.
	* @param n Length of the vector.
	*/

	static std::vector<double> createT0Vector(int n /**int. Length of the vector. */);




};
#endif
