#pragma once
#include "random_generator/random_generator.h"

class LIBRARY_API LCGGenerator : public RandomGenerator {
public:
	static const size_t multiplier;
	static const size_t increment;
	static const size_t modulus;

	size_t itsSeed;
	LCGGenerator(const long& size, const size_t& seed = 10.);
	void generateValues();
};