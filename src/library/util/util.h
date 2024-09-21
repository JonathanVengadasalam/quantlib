#pragma once
#include "export/export.h"

#define PI 3.14159265358979323846

class LIBRARY_API Vector {
private:
	void swap(double& a, double& b);
	int partition(double* vector, const long& low, const long& high);
	void quickSort(double* vector, const long& low, const long& high);
	double sum(const double& mean, const double& sdtdev, const int& exposant);
public:
	double* itsArray;
	long itsSize;
	Vector();
	Vector(const long& size, double* vector = nullptr);
	Vector(const Vector& vector);
	~Vector();
	double& operator[](const long& ind);
	const double operator[](const long& ind) const;
	void reSize(const long& size, const bool& keepValues = false);
	void swap(const long& i, const long& j);
	void quickSort();
	long maxIndex();
	double sum();
	double mean();
	double variance(const double& mean);
	double skewness(const double& mean, const double& variance);
	double kurtosis(const double& mean, const double& variance);
};

class LIBRARY_API Cube : public Vector {
public:
	long itsSizeX;
	long itsSizeY;
	long itsSizeZ;
	Cube();
	Cube(const long& xSize, const long& ySize, const long& zSize, double* vector = nullptr);
	Cube(const Cube& cube);
	~Cube();
	double& get(const long& x, const long& y, const long& z);
	const double get(const long& x, const long& y, const long& z) const;
	void reSize(const long& x, const long& y, const long& z, const bool& keepValues = false);
};