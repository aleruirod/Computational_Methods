#include "vector.h"
#include "matrix.h"


class Solution {

	double deltaX = 0.05; // can be changed for different problems.
	double deltaT = 0.01;// can be changed for different problems.
	double D = 0.1;// Diffusivity of the material in the problem.
	int n = 20;// The size of the solution should be 1 ft / deltaX.
	Matrix allSolutions; //We collect in a matrix all solutions we think will be relevant.
	Vector solution;// Vector with the solution for a certain timestep.

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

	Solution(Vector& v /**< Vector&. vector taken as solution */);

	// GETTERS
	/**
	* Returns all solutions stored in the Solution object.
	* @see getCurrentSolution()
	*/

	Matrix getAllSolutions();

	/**
	* Returns current solution stored in the object.
	* @see getAllSolutions()
	*/

	Vector getCurrentSolution();

	// SETTERS
	/**
	* changes allSolutions
	* @see setCurrentSolution()
	*/

	void setAllSolutions();

	/**
	* changes the solution attribute of the object.
	* @see setAllSolutions()
	*/

	void setCurrentSolution();
};


