#pragma once
#include "export/export.h"
#include "vector.h"

#define PI 3.14159265358979323846

class LIBRARY_API Square {

};

class LIBRARY_API Cube : public DblVector {
public:
	long itsSizeX;
	long itsSizeY;
	long itsSizeZ;
	Cube();
	Cube(const long& xSize, const long& ySize, const long& zSize, double* vector = nullptr);
	Cube(const Cube& cube, const bool& deepCopy = false);
	~Cube();
	double& get(const long& x, const long& y, const long& z);
	const double get(const long& x, const long& y, const long& z) const;
	void reSize(const long& x, const long& y, const long& z, const bool& keepValues = false);
};