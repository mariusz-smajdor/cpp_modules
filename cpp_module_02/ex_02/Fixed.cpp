#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Setters and getters

int Fixed::getValue() const {
    return _value;
}

// Operator overload functions

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.getValue();
    return out;
}
