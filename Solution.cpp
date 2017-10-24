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
	std::vector<std::vector<double>> newMat = Solution::getAllSolutions();//set the size beforehand.
	Solution::allSolutions;
}

void Solution::setCurrentSolution(std::vector<double> v) {
	Solution::solution = v;
}