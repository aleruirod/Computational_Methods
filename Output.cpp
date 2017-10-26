#include <iostream>
#include "Output.h"


void Output::printSolution(std::vector<std::vector<double>> v) {

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << "\n";
	}
}