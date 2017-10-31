#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector> // we will use the standard vector library provided by the C++ language.


/**
* The Solution class is the base for
* \n all other methods used as they all share 
* \n some common characteristics.
*
*/

class Solution {

public:
	
	// CONSTRUCTORS
	/**
	*Creates an empty Solution object
	* @see Solution(Vector<Vector<double>> sols);
	*/

	Solution();

	/**
	* creates a Solution object from a vector of double vectors.
	* @see Solution();
	* @param sols Vector of double vectors that the new Solution will use.
	*/

	Solution(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that the new Solution will use. */);

	// GETTERS
	/**
	* Returns all solutions stored in the Solution object.
	*/

	std::vector<std::vector<double>> getAllSolutions();

	// STORING
	/**
	* adds a new solution to allSolutions.
	*/

	void addToAllSolutions(std::vector<double> v);

protected:
	double deltaX = 0.05; //!< Space step. Can be changed for different problems.
	double deltaT = 0.01;//!< Time step. Can be changed for different problems.
	double D = 0.1;//!< Diffusivity of the material in the problem.
	double L = 1.0;//!< Spatial size of the problem.
	int n = 20;//!< The size of each solution should be: L / deltaX. This controls the size of the solution vectors for every single timestep.
	std::vector<std::vector<double>> allSolutions; //!< We collect in a vector of vectors all solutions we think will be relevant.
	int allSolPos = 0;//!< We control the number of elements inside the allSolutions vector.

};
#endif

