#pragma once
#include "random_generator/random_generator.h"

class LIBRARY_API ToreGenerator : public RandomGenerator {
public:
	size_t itsPrime;
	ToreGenerator(const long& size, const size_t& prime = 19);
	void generateValues();
};