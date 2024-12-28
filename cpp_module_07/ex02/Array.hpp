#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T *_arr;
        unsigned int _size;

    public:
        // Constructors and Destructor
        Array(void);
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array(void);

        // Operator Overloads
        Array &operator=(const Array &copy);
        T &operator[](unsigned int i) const;

        // Member Functions
        unsigned int size(void) const;

        // Exceptions
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

template <typename T>
std::ostream & operator<<(std::ostream &out, const Array<T>& arr);