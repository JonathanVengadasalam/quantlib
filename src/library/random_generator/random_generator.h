#pragma once
#include "util/util.h"

class LIBRARY_API RandomGenerator {
public:
	Cube* itsCube;
	RandomGenerator(const long& xSize, const long& ySize = 1, const long& zSize = 1, double* vector = nullptr);
	virtual ~RandomGenerator();
	virtual void generateValues() = 0;
	virtual double probability(const double& observation);
	Vector kolmogorovSmirnov(const bool& forceSort = false);
};