#ifndef DUFORTFRANKEL_H
#define DUFORTFRANKEL_H

#include "Solution.h"

/**
* The DuFortFrankelMethod is an implicit and unconditionally stable method.
* \n This method is a variation of the RichardsonMethod.
*/

class DuFortFrankelMethod : public Solution {

	public:

		// CONSTRUCTORS
		/**
		* Creates an empty DuFortFrankelMethod object
		* @see DuFortFrankelMethod(Vector v);
		*/

		DuFortFrankelMethod();

		/**
		* Creates an DuFortFrankelMethod object from an array.
		* @see DuFortFrankelMethod();
		* @param v Vector taken as solution
		*/

		DuFortFrankelMethod(std::vector<double> v /**< std::vector<double>. vector taken as solution */);

		/**
		* Computes and stores the values for the Solution using this method.
		*/

		void compute();
};
#endif