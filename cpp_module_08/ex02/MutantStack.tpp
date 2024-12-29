#include "MutantStack.hpp"

// Constructors and destructor

template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) {
    std::cout << "MutantStack copy constructor called" << std::endl;
    *this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
    std::cout << "MutantStack destructor called" << std::endl;
}

// Operator overloads

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy) {
    std::cout << "MutantStack assignment operator called" << std::endl;
    if (this != &copy) {
        this->c = copy.c;
    }
    return *this;
}

// Member functions

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}
