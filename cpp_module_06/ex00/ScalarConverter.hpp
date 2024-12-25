#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter {
    private:
        // Constructors and Destructor
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter(void);

        // Operators
        ScalarConverter &operator=(const ScalarConverter &copy);

    public:
        // Member functions
        static void convert(const std::string &representation);
};
