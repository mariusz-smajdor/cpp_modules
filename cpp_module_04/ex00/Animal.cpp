#include "Animal.hpp"

Animal::Animal(void): _type("undefined") {
    std::cout << "Animal " << this->_type << " created with default constructor." << std::endl;
}

Animal::Animal(const std::string &type): _type(type) {
    std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(const Animal &copy) {
    *this = copy;
    std::cout << "Animal " << this->_type << " copied." << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Animal " << this->_type << " destroyed." << std::endl;
}

const Animal &Animal::operator=(const Animal &copy) {
    std::cout << "Animal assignment operator for " << this->_type << " called." << std::endl;
    this->_type = copy.getType();
    return *this;
}

const std::string &Animal::getType(void) const {
    return this->_type;
}

void	Animal::setType(const std::string &type) {
	this->_type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal " << this->_type << " made a sound!" << std::endl;
}
