#pragma once
#include "util/util.h"
#include "util/vector.h"

class LIBRARY_API RandomGenerator {
public:
	Cube* itsCube;
	RandomGenerator(const long& xSize, const long& ySize = 1, const long& zSize = 1, double* vector = nullptr);
	virtual ~RandomGenerator();
	virtual void generateValues() = 0;
	virtual double probability(const double& observation);
	DblVector kolmogorovSmirnov(const bool& forceSort = false);
};