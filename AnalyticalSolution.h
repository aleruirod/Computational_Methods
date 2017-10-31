#ifndef ANALYTICAL_H
#define ANALYTICAL_H

#include "Solution.h"ç

/**
* the Analytical Solution of the problem gives us the exact right
* \n  values for our case. This solution will be used to compare
* \n the values we get from the other methods used.
*/

class AnalyticalSolution : public Solution {
	public:

		// CONSTRUCTORS
		/**
		* Creates an empty AnalyticalSolution object
		* @see AnalyticalSolution(Vector v);
		*/

		AnalyticalSolution();

		/**
		* creates a Solution object from an array.
		* @see AnalyticalSolution();
		* @param v Vector taken as solution
		*/

		AnalyticalSolution(std::vector<double> v /**< std::vector<double>. vector taken as solution */);

		/**
		* Computes and stores the values for the Solution using this method.
		*/

		void compute();

	protected:
		const double PI = 3.141592; //!< Pi is needed in order to calculate the analytical solution of the problem.
};

#endif
