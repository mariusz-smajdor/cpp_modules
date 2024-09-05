#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

// Setters and getters

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(const int raw) {
    _value = raw;
}

// Operator overload comparison functions

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// Operator overload arithmetic functions

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed ret;

	ret.setRawBits(_value + other._value);
	return ret;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed ret;

    ret.setRawBits(_value - other._value);
    return ret;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed ret;

    ret.setRawBits(_value * other._value);
    return ret;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed ret;

    ret.setRawBits(_value / other._value);
    return ret;
}

// Operator overload increment, decrement functions

Fixed& Fixed::operator++(void) {
	++_value;
	return *this;
}

Fixed& Fixed::operator--(void) {
	--_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed post = *this;

	_value++;
	return post;
}

Fixed Fixed::operator--(int) {
	Fixed post = *this;

	_value--;
	return post;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.getRawBits();
    return out;
}
