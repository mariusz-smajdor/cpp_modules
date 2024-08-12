#include "Fixed.hpp"

int main( void ) {
    Fixed a;           // Default constructor
    Fixed b(5);        // Integer constructor

    std::cout << "Raw bits of a: " << a.getRawBits() << std::endl;
    std::cout << "Raw bits of b: " << b.getRawBits() << std::endl;

    return 0;
}