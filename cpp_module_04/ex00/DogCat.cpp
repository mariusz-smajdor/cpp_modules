#include "DogCat.hpp"

Dog::Dog(void): _type("Dog") {
	std::cout << "Dog from Animal " << Animal::_type << " created with default constructor." << std::endl;
}

Dog::Dog(const std::string &type): Animal(type), _type("Dog") {
	std::cout << "Dog from Animal " << Animal::_type << " created." << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy) {
	*this = copy;
	std::cout << "Dog from Animal " << Animal::_type << " copied." << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog from Animal " << Animal::_type << " destroyed." << std::endl;
}

const Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Assignment operator for Dog from Animal " << Animal::_type << " called." << std::endl;
	Animal::operator=(copy);
	return (*this);
}

const std::string &Dog::getType(void) const {
	return (this->_type);
}

void Dog::setType(const std::string &type) {
	this->_type = type;
}

void Dog::makeSound(void) const {
	std::cout << "Dog From Animal " << Animal::_type << " goes Bark!" << std::endl;
}

Cat::Cat(void): _type("Cat") {
	std::cout << "Cat from Animal " << Animal::_type << " created with default constructor." << std::endl;
}

Cat::Cat(std::string const &type):Animal(type), _type("Cat") {
	std::cout << "Cat from Animal " << Animal::_type << " created." << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy) {
	*this = copy;
	std::cout << "Cat from Animal " << Animal::_type << " copied." << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat from Animal " << Animal::_type << " destroyed." << std::endl;
}

const Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Assignment operator for Cat from Animal " << Animal::_type << " called." << std::endl;
	Animal::operator=(copy);
	return (*this);
}

const std::string &Cat::getType(void) const {
	return (this->_type);
}

void Cat::setType(const std::string &type) {
	this->_type = type;
}

void Cat::makeSound(void) const {
	std::cout << "Cat From Animal " << Animal::_type << " goes Meow!" << std::endl;
}
