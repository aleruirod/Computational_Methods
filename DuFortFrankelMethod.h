#ifndef DUFORTFRANKEL_H
#define DUFORTFRANKEL_H

#include "Solution.h"

/**
* The DuFortFrankelMethod is an explicit and unconditionally stable method.
* \n This method is a variation of the RichardsonMethod.
*/

class DuFortFrankelMethod : public Solution {

	public:

		// CONSTRUCTORS
		/**
		* Creates an empty DuFortFrankelMethod object
		* @see DuFortFrankelMethod(Vector<Vector<double>> sols);
		*/

		DuFortFrankelMethod();

		/**
		* Creates an DuFortFrankelMethod object from a vector of double vectors.
		* @see DuFortFrankelMethod();
		* @param sols Vector of double vectors that the new Solution will use.
		*/

		DuFortFrankelMethod(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that the new Solution will use. */);

		// COMPUTATION
		/**
		* Computes and stores the values for the Solution using this method.
		*/

		void compute();
};
#endif