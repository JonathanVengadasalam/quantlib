#include "pch.h"
#include "random_generator/lcg_generator.h"

LCGGenerator::LCGGenerator(const long& size, const size_t& seed) 
	: RandomGenerator(size), itsSeed(seed) {}
void LCGGenerator::generateValues() {
	size_t x = itsSeed;
	double doubled_modulus = static_cast<double>(modulus);
	double* vectArray = itsCube->itsArray;
	for (long i = 0; i < itsCube->itsSize; ++i) {
		x = (multiplier * x + increment) % modulus;
		vectArray[i] = x / doubled_modulus;
	}
}

const size_t LCGGenerator::multiplier = 16807;
const size_t LCGGenerator::increment = 0;
const size_t LCGGenerator::modulus = (size_t)std::pow(2, 31) - 1;