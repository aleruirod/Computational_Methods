#ifndef DUFORTFRANKEL_H
#define DUFORTFRANKEL_H

#include "Solution.h"

class DuFortFrankelMethod : public Solution {

	public:

		DuFortFrankelMethod();

		DuFortFrankelMethod(std::vector<double> v);

		void compute();
};
#endif