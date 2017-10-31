#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include "Solution.h"//we will print Solution objects.


/**
* The Output class is utilised to export the content
* \n of the solutions as files or simply show the 
* \n results on the console.
*
*/

class Output {
	public:

		/**
		* Prints on console all the solutions stored in a Solution object.
		* @param v This should be the allSolutions attribute from the Solution object we want to check.
		*/

		static void printSolution(std::vector<std::vector<double>> v);

};
#endif
