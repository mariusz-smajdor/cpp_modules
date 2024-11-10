#include "Animal.hpp"

Animal::Animal(void): _type("undefined") {
	std::cout << "Animal created with default constructor." << std::endl;
}

Animal::Animal(const std::string &type): _type(type) {
	std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << "Animal copied." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destroyed." << std::endl;
}

const Animal &Animal::operator=(const Animal &copy) {
	this->_type = copy.getType();
	std::cout << "Assignment operator for Animal called." << std::endl;
	return (*this);
}

const std::string &Animal::getType(void) const {
	return (this->_type);
}

void Animal::setType(const std::string &type) {
	this->_type = type;
}

void Animal::makeSound(void) const {
	std::cout << "Animal made a sound!" << std::endl;
}
