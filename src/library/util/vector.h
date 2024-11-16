#pragma once

template <typename T>
class Vector {
private:
	// internal_memory_tools
	void shareOwnership(const Vector<T>& vector);
	T* arrayAllocation(const long& size);
	void decrementRefCount();
	// internals
	void swap(T& a, T& b);
	int partition(T* vector, const long& low, const long& high);
	void quickSort(T* vector, const long& low, const long& high);
	double sum(const double& mean, const double& sdtdev, const int& exposant);
public:
	// attributs
	T* itsArray;
	long itsSize;
	int* itsRefCount;
	// constructor
	Vector<T>();
	Vector<T>(const long& size, T* vector = nullptr);
	Vector<T>(const Vector<T>& vector, const bool& deepCopy = false);
	~Vector<T>();
	// operators
	Vector<T>& operator=(const Vector<T>& other);
	T& operator[](const long& ind);
	const T operator[](const long& ind) const;
	// public tools
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

using DblVector = Vector<double>;
using LngVector = Vector<long>;

#include "vector_impl.tpp"