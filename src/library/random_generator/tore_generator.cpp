#include "pch.h"
#include "random_generator/tore_generator.h"

ToreGenerator::ToreGenerator(const long& size, const size_t& prime)
	: RandomGenerator(size), itsPrime(prime) {}
void ToreGenerator::generateValues() {
	double* vectArray = itsCube->itsArray;
	for (long i = 0; i < itsCube->itsSize; ++i) {
		vectArray[i] = (i + 1) * std::sqrt(itsPrime) - std::floor((i + 1) * std::sqrt(itsPrime));
	}
}