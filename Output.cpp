#include <iostream>
#include <fstream> 
#include <math.h>

#include "Output.h"

/**
* Print all solutions from a vector of double vectors.
*/

void Output::printSolution(std::vector<std::vector<double>> v) {

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " "; // for every value in a timestep, we introduce a blank space as separation.
		}
		std::cout << "\n"; // we introduce a line break between each different solution vector.
	}
}

void Output::exportSolution(Solution obj, double xSize, std::string name) {

	for (int i = 0; i < obj.getAllSolutions().size(); i++) {

		std::string aux = name;
		aux += std::to_string(xSize*i)+".dat";

		std::ofstream outfile(aux);

		for (int j = 0; j < obj.getAllSolutions()[0].size(); j++)
			outfile << obj.getDeltaX()*j << " " << obj.getAllSolutions()[i][j] << "\n" << std::endl;
			
		outfile.close();

	}

}