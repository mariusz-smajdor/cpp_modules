#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Member functions

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(const int raw) {
	_value = raw;
}