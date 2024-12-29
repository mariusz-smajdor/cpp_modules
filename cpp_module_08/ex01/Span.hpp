#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span {
    private:
        // Member properties
        std::vector<int> _storage;
        unsigned int _size;
        unsigned int _pos;

        // Constructor
        Span();

    public:
        // Constructors and destructor
        Span(unsigned int size);    
        Span(const Span &copy);
        ~Span(void);

        // Operator overloads
        Span &operator=(const Span &copy);

        // Member functions
        void addNumber(int number);
        void addNumber(unsigned int ramge, time_t seed);
        unsigned int shortestSpan(void) const;
        unsigned int longestSpan(void) const;

        // Getters
        unsigned int getSize(void) const;
        unsigned int getPos(void) const;

        // Exceptions
        class StorageFullException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class InvalidVectorException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NoSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
