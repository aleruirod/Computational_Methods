#include <iostream>
#include <fstream>  

#include "Output.h"

/**
* Print all solutions from a vector of double vectors.
*/

void Output::printSolution(std::vector<std::vector<double>> v) {

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " "; // for every value in a timestep, we introduce a balnk space as separation.
		}
		std::cout << "\n"; // we introduce a line break between each different solution vector.
	}
}

void Output::exportSolution(Solution obj, double xSize, int n) {

	for (int i = 0; i < n; i++) {

		std::ofstream outfile(typeid(obj).name() + i);

		for (int j = 0; j < obj.getAllSolutions()[0].size(); j++)
			outfile << xSize*i << " " << obj.getAllSolutions()[i][j] << "\n" << std::endl;
			
		outfile.close();

	}

}