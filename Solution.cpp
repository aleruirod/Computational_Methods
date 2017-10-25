#include "Solution.h"

// CONSTRUCTORS
/*
* Default constructor (empty solution)
*/

Solution::Solution() {}

/*
* Constructor from an array.
*/

Solution::Solution(std::vector<double> v) {
	Solution::setCurrentSolution(v);
}

std::vector<std::vector<double>> Solution::getAllSolutions() {
	return Solution::allSolutions;
}

std::vector<double> Solution::getCurrentSolution() {
	return Solution::solution;
}

void Solution::addToAllSolutions(std::vector<double> v) {
	Solution::allSolutions.resize(allSolPos + 1);
	Solution::allSolutions[allSolPos] = v;
	Solution::allSolPos++;
}

void Solution::setCurrentSolution(std::vector<double> v) {
	Solution::solution = v;
}