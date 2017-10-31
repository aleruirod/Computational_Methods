#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>


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
	* @see Solution(Vector v);
	*/

	Solution();

	/**
	* creates a Solution object from an array.
	* @see Solution();
	* @param v Vector taken as solution
	*/

	Solution(std::vector<double> v /**< std::vector<double>. vector taken as solution */);

	// GETTERS
	/**
	* Returns all solutions stored in the Solution object.
	* @see getCurrentSolution()
	*/

	std::vector<std::vector<double>> getAllSolutions();

	/**
	* Returns current solution stored in the object.
	* @see getAllSolutions()
	*/

	std::vector<double> getCurrentSolution();

	// SETTERS
	/**
	* changes allSolutions
	* @see setCurrentSolution()
	*/

	void addToAllSolutions(std::vector<double> v);

	/**
	* changes the solution attribute of the object.
	* @see setAllSolutions()
	*/

	void setCurrentSolution(std::vector<double> v);

protected:
	double deltaX = 0.05; //!< Space step. Can be changed for different problems.
	double deltaT = 0.01;//!< Time step. Can be changed for different problems.
	double D = 0.1;//!< Diffusivity of the material in the problem.
	double L = 1.0;//!< Spatial size of the problem.
	int n = 20;//!< The size of each solution should be: L / deltaX. This controls the size of the solution vectors for every single timestep.
	std::vector<std::vector<double>> allSolutions; //!< We collect in a vector of vectors all solutions we think will be relevant.
	int allSolPos = 0;//!< We control the number of elements inside the allSolutions vector.
	std::vector<double> solution;//!< Vector with the solution for a certain timestep.

};
#endif

