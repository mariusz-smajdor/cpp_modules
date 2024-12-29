#pragma once

#include <string>
#include <list>
#include <iostream>

class RPN {
    public:
        RPN();
        RPN(const RPN &src);
        ~RPN();
        RPN &operator =(const RPN &src);

        float result(const std::string expr);

        class BadExpressionException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadDivision: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class RemainingOperators: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
