#include "pch.h"
#include "util.h"

Cube::Cube() : Vector(), itsSizeX(0), itsSizeY(0), itsSizeZ(0) {}
Cube::Cube(const long& xSize, const long& ySize, const long& zSize, double* vector)
    : Vector(xSize * ySize * zSize, vector), itsSizeX(xSize), itsSizeY(ySize), itsSizeZ(zSize) {}
Cube::Cube(const Cube& cube, const bool& deepCopy)
    : Vector(cube, deepCopy), itsSizeX(cube.itsSizeX), itsSizeY(cube.itsSizeY), itsSizeZ(cube.itsSizeZ) {}
Cube::~Cube() {}
double& Cube::get(const long& x, const long& y, const long& z) {
    return itsArray[x * itsSizeY * itsSizeZ + y * itsSizeZ + z];
}
const double Cube::get(const long& x, const long& y, const long& z) const {
    return itsArray[x * itsSizeY * itsSizeZ + y * itsSizeZ + z];
}
void Cube::reSize(const long& x, const long& y, const long& z, const bool& keepValues) {
    itsSizeX = x;
    itsSizeY = y;
    itsSizeZ = z;
    DblVector::reSize(x * y * z, keepValues);
}