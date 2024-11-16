#pragma region constructors
template <typename T>
Vector<T>::Vector() : itsSize(0), itsArray(nullptr), itsRefCount(new int(1)) {}
template <typename T>
Vector<T>::Vector(const long& size, T* vector)
    : itsSize(size), itsArray(vector ? vector : arrayAllocation(size)), itsRefCount(new int(1)) {
}
template <typename T>
Vector<T>::Vector(const Vector& vector, const bool& deepCopy) : itsSize(vector.itsSize) {
    if (deepCopy) {
        T* tmpArray = vector.itsArray;
        itsArray = arrayAllocation(vector.itsSize);
        for (int i = 0; i < itsSize; ++i) {
            itsArray[i] = tmpArray[i];
        }
        itsRefCount = new int(1);
    }
    else {
        shareOwnership(vector);
    }
}
template <typename T>
Vector<T>::~Vector() {
    decrementRefCount();
}
#pragma endregion constructor

#pragma region operators
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        decrementRefCount();
        shareOwnership(other);
    }
    return *this;
}
template <typename T>
T& Vector<T>::operator[](const long& ind) {
    return itsArray[ind];
}
template <typename T>
const T Vector<T>::operator[](const long& ind) const {
    return itsArray[ind];
}
#pragma endregion operators

#pragma region internal_memory_tools
template <typename T>
void Vector<T>::shareOwnership(const Vector<T>& vector) {
    itsArray = vector.itsArray;
    itsRefCount = vector.itsRefCount;
    ++(*itsRefCount);
}
template <typename T>
T* Vector<T>::arrayAllocation(const long& size) {
    T* newArray = nullptr;
    try {
        if (size > 0) {
            newArray = new double[size];
        }
    }
    catch (std::bad_alloc& e) {
        std::cerr << "memory allocation error : " << e.what() << std::endl;
    }
    return newArray;
}
template <typename T>
void Vector<T>::decrementRefCount() {
    if (itsRefCount && --(*itsRefCount) == 0) {
        delete[] itsArray;
        delete itsRefCount;
    }
}
#pragma endregion internal_memory_tools

#pragma region internals
template <typename T>
void Vector<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
int Vector<T>::partition(T* array, const long& low, const long& high) {
    T pivot = array[high];
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
template <typename T>
void Vector<T>::quickSort(T* array, const long& low, const long& high) {
    if (low < high) {
        long pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
template <typename T>
double Vector<T>::sum(const double& mean, const double& sdtdev, const int& exposant) {
    double sum = 0.;
    for (long i = 0; i < itsSize; ++i) {
        sum += std::pow((itsArray[i] - mean) / sdtdev, exposant);
    }
    return sum;
}
#pragma endregion internals

#pragma region public_tools
template <typename T>
void Vector<T>::reSize(const long& size, const bool& keepValues) {
    T* newArray = arrayAllocation(size);
    if (keepValues and newArray != nullptr) {
        long minSize = size < itsSize ? size : itsSize;
        for (long i = 0; i < minSize; ++i) {
            newArray[i] = itsArray[i];
        }
    }
    decrementRefCount();
    itsRefCount = new int(1);
    itsArray = newArray;
    itsSize = size;
}
template <typename T>
void Vector<T>::swap(const long& i, const long& j) {
    swap(itsArray[i], itsArray[j]);
}
template <typename T>
void Vector<T>::quickSort() {
    quickSort(itsArray, 0, itsSize - 1);
}
template <typename T>
long Vector<T>::maxIndex() {
    long ind = -1;
    if (itsSize > 0) {
        ind = 0;
        T max = itsArray[0];
        for (long i = 1; i < itsSize; ++i) {
            if (itsArray[i] > max) {
                ind = i;
                max = itsArray[i];
            }
        }
    }
    return ind;
}
template <typename T>
double Vector<T>::sum() {
    return sum(0., 1., 1.);
}
template <typename T>
double Vector<T>::mean() {
    return sum(0., 1., 1.) / itsSize;
}
template <typename T>
double Vector<T>::variance(const double& mean) {
    return sum(mean, 1., 2.) / itsSize;
}
template <typename T>
double Vector<T>::skewness(const double& mean, const double& variance) {
    return sum(mean, std::sqrt(variance), 3.) / itsSize;
}
template <typename T>
double Vector<T>::kurtosis(const double& mean, const double& variance) {
    return -3 + sum(mean, std::sqrt(variance), 4.) / itsSize;
}
#pragma endregion public_tools