#include "pch.h"
#include "util.h"
#include <cmath>

void Vector::swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}
int Vector::partition(double* array, const long& low, const long& high) {
    double pivot = array[high];
    long i = low - 1;

    for (long j = low; j <= high - 1; ++j) {
        if (array[j] <= pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
void Vector::quickSort(double* array, const long& low, const long& high) {
    if (low < high) {
        long pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

Vector::Vector() : itsSize(0), itsArray(nullptr) {}
Vector::Vector(const long& size, double* vector) : itsSize(size) {
    if (vector == nullptr && size > 0) {
        itsArray = new double[size];
    }
    else {
        itsArray = vector;
    }
}
Vector::Vector(const Vector& vector) {
    itsSize = vector.itsSize;
    double* array = vector.itsArray;
    itsArray = new double[itsSize];
    for (int i = 0; i < itsSize; ++i) {
        itsArray[i] = array[i];
    }
}
Vector::~Vector() {
	delete[] itsArray;
}
double& Vector::operator[](const long& ind) {
    return itsArray[ind];
}
const double Vector::operator[](const long& ind) const {
    return itsArray[ind];
}

void Vector::quickSort() {
    quickSort(itsArray, 0, itsSize - 1);
}
long Vector::maxIndex() {
    long ind = -1;
    if (itsSize > 0) {
        ind = 0;
        double max = itsArray[0];
        for (long i = 1; i < itsSize; ++i) {
            if (itsArray[i] > max) {
                ind = i;
                max = itsArray[i];
            }
        }
    }
    return ind;
}
double Vector::sum(const double& mean, const double& sdtdev, const int& exposant) {
    double sum = 0.;
    for (long i = 0; i < itsSize; ++i) {
        sum += std::pow((itsArray[i] - mean) / sdtdev, exposant);
    }
    return sum;
}
double Vector::sum() {
    return sum(0., 1., 1.);
}
double Vector::mean() {
    return sum(0., 1., 1.) / itsSize;
}
double Vector::variance(const double& mean) {
    return sum(mean, 1., 2.) / itsSize;
}
double Vector::skewness(const double& mean, const double& variance) {
    return sum(mean, std::sqrt(variance), 3.) / itsSize;
}
double Vector::kurtosis(const double& mean, const double& variance) {
    return - 3 + sum(mean, std::sqrt(variance), 4.) / itsSize;
}