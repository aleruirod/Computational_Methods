#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string>
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
		* @param sols This should be the allSolutions attribute from the Solution object we want to print.
		*/

		static void printSolution(std::vector<std::vector<double>> sols /**< std::vector<std::vector<double>>. Vector of double vectors that we want to print. */);

		static void exportSolution(Solution obj, double xSize, std::string name);

};
#endif
