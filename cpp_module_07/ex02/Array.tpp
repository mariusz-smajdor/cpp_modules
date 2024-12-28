#include "Array.hpp"

// Constructors and Destructor

template <typename T>
Array<T>::Array(void) : _arr(new T[0]), _size(0) {
    std::cout << "Array default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {
    std::cout << "Array constructor called\n";
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]), _size(copy._size) {
    std::cout << "Array copy constructor called\n";
    for (unsigned int i = 0; i < _size; i++) {
        _arr[i] = copy._arr[i];
    }
}

template <typename T>
Array<T>::~Array(void) {
    std::cout << "Array destructor called\n";
    delete[] _arr;
}

// Operator Overloads

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
    std::cout << "Array assignment operator called\n";
    if (this != &copy) {
        delete[] _arr;
        _arr = new T[copy._size];
        _size = copy._size;
        for (unsigned int i = 0; i < _size; i++) {
            _arr[i] = copy._arr[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const {
    if (i >= _size) {
        throw OutOfBoundsException();
    }
    return _arr[i];
}

// Member Functions

template <typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}

// Exceptions

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Array index out of bounds";
}

// Non-member Functions

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T>& arr) {
    out << "Array: [";
    for (unsigned int i = 0; i < arr.size(); i++) {
        out << arr[i];
        if (i < arr.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
