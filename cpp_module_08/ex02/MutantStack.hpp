#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        // Constructors and destructor
        MutantStack();
        MutantStack(const MutantStack &copy);
        ~MutantStack();

        // Operator overloads
        MutantStack &operator=(const MutantStack<T> &copy);

        // Member functions
        typedef typename std::stack<T>::container_type container_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;

        iterator begin(void);
        iterator end(void);
        const_iterator begin(void) const;
        const_iterator end(void) const;
};
