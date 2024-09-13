#include "Fixed.hpp"

int main( void ) {
    Fixed a;           // Default constructor
    Fixed b(5);        // Integer constructor

    std::cout << "Raw bits of a: " << a.getRawBits() << std::endl;
    std::cout << "Raw bits of b: " << b.getRawBits() << std::endl;

    std::cout << "Float value of a: " << a.toFloat() << std::endl;
    std::cout << "Float value of b: " << b.toFloat() << std::endl;

    std::cout << "Int value of a: " << a.toInt() << std::endl;
    std::cout << "Int value of b: " << b.toInt() << std::endl;

    return 0;
}