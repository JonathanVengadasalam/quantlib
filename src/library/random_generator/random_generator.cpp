#include "pch.h"
#include "random_generator/random_generator.h"

RandomGenerator::RandomGenerator(const long& xSize, const long& ySize, const long& zSize, double* vector) {
	itsCube = new Cube(xSize, ySize, zSize, vector);
}
RandomGenerator::~RandomGenerator() {
	delete itsCube;
}
double RandomGenerator::probability(const double& observation) {
	return observation;
}
Vector RandomGenerator::kolmogorovSmirnov(const bool& forceSort) {
	if (forceSort) {
		itsCube->quickSort();
	}
	Vector vector(itsCube->itsSize);
	double* vectorArray = vector.itsArray;
	double* localArray = itsCube->itsArray;
	double size = itsCube->itsSize;
	for (long i = 0; i < itsCube->itsSize; ++i) {
		vectorArray[i] = std::abs(probability(localArray[i]) - (i + 1) / size);
	}
	return vector;
}