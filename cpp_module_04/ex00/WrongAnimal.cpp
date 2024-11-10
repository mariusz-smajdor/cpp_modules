#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("undefined") {
	std::cout << "WrongAnimal " << this->_type << " created with default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type): _type(type) {
	std::cout << "WrongAnimal " << this->_type << " created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
	std::cout << "WrongAnimal " << this->_type << " copied." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal " << this->_type << " destroyed." << std::endl;
}

const WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	std::cout << "Assignment operator for WrongAnimal " << this->_type << " called." << std::endl;
	this->_type = copy.getType();
	return (*this);
}

const std::string &WrongAnimal::getType(void) const {
	return (this->_type);
}

void WrongAnimal::setType(const std::string &type) {
	this->_type = type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal " << this->_type << " made a sound!" << std::endl;
}

WrongCat::WrongCat(void): _type("WrongCat") {
	std::cout << "WrongCat from WrongAnimal " << WrongAnimal::_type << " created with default constructor." << std::endl;
}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type), _type("WrongCat") {
	std::cout << "WrongCat from WrongAnimal " << WrongAnimal::_type << " created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy) {
	*this = copy;
	std::cout << "WrongCat from WrongAnimal " << WrongAnimal::_type << " copied." << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat from WrongAnimal " << WrongAnimal::_type << " destroyed." << std::endl;
}

const WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "Assignment operator for WrongCat from WrongAnimal " << WrongAnimal::_type << " called." << std::endl;
	WrongAnimal::operator=(copy);
	return (*this);
}

const std::string &WrongCat::getType(void) const {
	return (this->_type);
}

void WrongCat::setType(const std::string &type) {
	this->_type = type;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat From WrongAnimal " << WrongAnimal::_type << " goes Meow!" << std::endl;
}

