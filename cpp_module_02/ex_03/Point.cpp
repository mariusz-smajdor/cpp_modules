#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

const Fixed& Fixed::getX(void) const {
    return _x;
}

const Fixed& Fixed::getY(void) const {
    return _y;
}
