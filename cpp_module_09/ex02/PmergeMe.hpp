#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define VERBOSE false

template<typename T, template <typename, typename> class Container>
class PmergeMe {
    public:
        // Constructors and destructor
        PmergeMe<T, Container>();
        PmergeMe<T, Container>(const PmergeMe<T, Container> &src);
        ~PmergeMe<T, Container>();

        // Operator overload
        PmergeMe<T, Container> &operator=(const PmergeMe<T, Container> &src);

        // Member functions
        Container<T, std::allocator<T> > sort(const Container<T, std::allocator<T> > &array) const;
};

#include "PmergeMe.tpp"
