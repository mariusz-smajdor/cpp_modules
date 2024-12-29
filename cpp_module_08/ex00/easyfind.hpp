#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
    public:
        ValueNotFoundException(int value) {
            std::cout << "Value " << value;
        }

        virtual const char *what() const throw() {
            return " not found!";
        }
};

template <typename T>
void easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw ValueNotFoundException(value);
    }
    std::cout << "Value " << value << " found!" << std::endl;
}