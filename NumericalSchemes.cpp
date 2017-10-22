#include "matrix.h"
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
	
double deltaX = 0.8;
double deltaT = 0.1;

int NROWS = 201;
int NCOLS = 101;


double sign(double a) {
	double res;
	if (a < 0)
		res = -1.0;
	else if (a == 0)
		res = 0.0;
	else
		res = 1.0;
	return res;
}

void createCSV(Matrix m, std::ofstream &s) {
	for (int i = 0; i < NROWS; i++)
	{

		for (int j = 0; j < NCOLS; j++)
		{
			if (j == NCOLS - 1)
				s << m[i][j];
			else
				s << m[i][j] << ",";
		}

		s << "\n";
	}
}

void upwind_ExplicitSol_Prob0(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("upwindScheme-Prob0.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix explicitSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		for (int j = 0; j < NCOLS; j++)
		{
			if (j == 0)
				explicitSolMatrix[i][j] = 0.0;
			else if (j == (NCOLS - 1))
				explicitSolMatrix[i][j] = 1.0;
			else if (i == 0)
				explicitSolMatrix[i][j] = (0.5*(sign( j * deltaX - 40.0) + 1.0));
			else
				explicitSolMatrix[i][j] = deltaT * (-(explicitSolMatrix[i - 1][j] - explicitSolMatrix[i - 1][j - 1]) / deltaX) + explicitSolMatrix[i - 1][j];
		}
	}

	createCSV(explicitSolMatrix, myfile);

	myfile.close();

	*inputMatrix = explicitSolMatrix;

}

void upwind_ExplicitSol_Prob1(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("upwindScheme-Prob1.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix explicitSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		for (int j = 0; j < NCOLS; j++)
		{
			if (j == 0)
				explicitSolMatrix[i][j] = 0.0;
			else if (j == (NCOLS - 1))
				explicitSolMatrix[i][j] = 0.0;
			else if (i == 0)
				explicitSolMatrix[i][j] = (0.5*(exp(-((j * deltaX - 40.0) * (j * deltaX - 40.0)))));
			else
				explicitSolMatrix[i][j] = deltaT * (-(explicitSolMatrix[i - 1][j] - explicitSolMatrix[i - 1][j - 1]) / deltaX) + explicitSolMatrix[i - 1][j];
		}
	}

	createCSV(explicitSolMatrix, myfile);

	myfile.close();

	*inputMatrix = explicitSolMatrix;

}

void centralDifference_ExplicitSol_Prob0(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("centralDifference-Prob0.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix explicitSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		explicitSolMatrix[i][0] = 0.0;
		explicitSolMatrix[i][NCOLS - 1] = 1.0;

		for (int j = 1; j < NCOLS - 1; j++)
		{
			if (i == 0)
				explicitSolMatrix[i][j] = (0.5*(sign(j * deltaX - 40.0) + 1.0));

		}
		
	}

	for (int i = 1; i < NROWS; i++)
	{
		for (int j = 1; j < NCOLS-1; j++)
		{
				explicitSolMatrix[i][j] = deltaT * (-(explicitSolMatrix[i - 1][j + 1] - explicitSolMatrix[i - 1][j - 1]) / (2 * deltaX)) + explicitSolMatrix[i - 1][j];
		}
	}

	createCSV(explicitSolMatrix, myfile);

	myfile.close();

	*inputMatrix = explicitSolMatrix;

}

void centralDifference_ExplicitSol_Prob1(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("centralDifference-Prob1.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix explicitSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		explicitSolMatrix[i][0] = 0.0;
		explicitSolMatrix[i][NCOLS - 1] = 0.0;

		for (int j = 1; j < NCOLS - 1; j++)
		{
			if (i == 0)
				explicitSolMatrix[i][j] = (0.5*(exp(-((j * deltaX - 40.0) * (j * deltaX - 40.0)))));

		}
	}

	for (int i = 1; i < NROWS; i++)
	{
		for (int j = 1; j < NCOLS - 1; j++)
		{
			
				explicitSolMatrix[i][j] = deltaT * (-(explicitSolMatrix[i - 1][j + 1] - explicitSolMatrix[i - 1][j - 1]) / (2 * deltaX)) + explicitSolMatrix[i - 1][j];
		}
	}

	createCSV(explicitSolMatrix, myfile);

	myfile.close();

	*inputMatrix = explicitSolMatrix;

}

void analyticalSolution_Prob0(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("analyticalSolution-Prob0.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix analyticalSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		for (int j = 0; j < NCOLS; j++)
		{
			analyticalSolMatrix[i][j] = (0.5* ( sign( ( j * deltaX - 40.0 ) - ( i * deltaT ) ) + 1.0 ) );
		}
	}

	createCSV(analyticalSolMatrix, myfile);

	myfile.close();

	*inputMatrix = analyticalSolMatrix;
}

void analyticalSolution_Prob1(Matrix *inputMatrix) {

	std::ofstream myfile;
	myfile.open("analyticalSolution-Prob1.csv");

	for (double cc = -40.0; cc < 40.1; cc += 0.8)
	{
		myfile << cc << ",";

		if (cc > 39.3)
			myfile << "\n";
	}

	Matrix analyticalSolMatrix = Matrix(*inputMatrix);

	for (int i = 0; i < NROWS; i++)
	{
		for (int j = 0; j < NCOLS; j++)
		{
			analyticalSolMatrix[i][j] = (0.5* (exp( -1.0*( (j * deltaX - 40.0) - (i * deltaT) )* ( (j * deltaX - 40.0) - (i * deltaT)))));
		}
	}

	createCSV(analyticalSolMatrix, myfile);

	myfile.close();

	*inputMatrix = analyticalSolMatrix;
}



int main() {

	Matrix calculatedMatrixUpwindProb0 = Matrix(NROWS, NCOLS);
	Matrix calculatedMatrixUpwindProb1 = Matrix(NROWS, NCOLS);
	Matrix calculatedMatrixCentralDifferenceProb0 = Matrix(NROWS, NCOLS);
	Matrix calculatedMatrixCentralDifferenceProb1 = Matrix(NROWS, NCOLS);
	Matrix analytSolMatrixProb0 = Matrix(NROWS, NCOLS);
	Matrix analytSolMatrixProb1 = Matrix(NROWS, NCOLS);

	upwind_ExplicitSol_Prob0(&calculatedMatrixUpwindProb0);
	upwind_ExplicitSol_Prob1(&calculatedMatrixUpwindProb1);
	centralDifference_ExplicitSol_Prob0(&calculatedMatrixCentralDifferenceProb0);
	centralDifference_ExplicitSol_Prob1(&calculatedMatrixCentralDifferenceProb1);
	analyticalSolution_Prob0(&analytSolMatrixProb0);
	analyticalSolution_Prob1(&analytSolMatrixProb1);

	std::cout << calculatedMatrixUpwindProb0;
	std::cout << calculatedMatrixUpwindProb1;
	std::cout << calculatedMatrixCentralDifferenceProb0;
	std::cout << calculatedMatrixCentralDifferenceProb1;
	std::cout << analytSolMatrixProb0;
	std::cout << analytSolMatrixProb1;

}




