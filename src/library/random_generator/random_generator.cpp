#include "pch.h"
#include "random_generator/random_generator.h"

RandomGenerator::RandomGenerator(const long& size) {
	itsVector = new Vector(size);
}
RandomGenerator::~RandomGenerator() {
	delete itsVector;
}