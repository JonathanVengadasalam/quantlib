#pragma once
#include "util/util.h"

class RandomGenerator {
public:
	Vector* itsVector;
	RandomGenerator(const long& size);
	virtual ~RandomGenerator();
	virtual void generateValues() = 0;
};