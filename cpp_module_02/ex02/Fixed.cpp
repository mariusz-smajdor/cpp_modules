#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intPart) : _value(intPart << _fractBits) {
        std::cout << "VALUE IN FLOAT: " << this->toFloat() << std::endl;
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float floatPart) : _value(static_cast<int>(roundf(floatPart * (1 << _fractBits)))) {
    std::cout << "VALUE IN FLOAT: " << this->toFloat() << std::endl;
	std::cout << "Float constructor called" << std::endl;
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

// Setters and getters

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(const int raw) {
    _value = raw;
}

// Member functions

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractBits;
}

Fixed& Fixed::min(Fixed &a, Fixed& b) {
	return (a > b ? b : a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a > b ? b : a);
}

Fixed& Fixed::max(Fixed &a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
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
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
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
    out << fixed.toFloat();
    return out;
}
