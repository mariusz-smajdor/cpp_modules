#include "DogCat.hpp"

Dog::Dog(void): Animal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog created with default constructor." << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy) {
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog copied." << std::endl;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destroyed." << std::endl;
}

const Dog &Dog::operator=(const Dog &copy) {
	Animal::operator=(copy);
	*this->_brain = *copy._brain;
	std::cout << "Assignment operator for Dog called." << std::endl;
	return (*this);
}

const std::string &Dog::getType(void) const {
	return (this->_type);
}

void Dog::setType(const std::string &type) {
	this->_type = type;
}

Brain &Dog::getBrain(void) const {
	return (*this->_brain);
}

void Dog::setBrain(const Brain &brain) {
	*this->_brain = brain;
}

void Dog::makeSound(void) const {
	std::cout << "Dog From Animal goes Bark!" << std::endl;
}

Cat::Cat(void): Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat created with default constructor." << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy) {
	*this = copy;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat copied." << std::endl;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destroyed." << std::endl;
}

const Cat &Cat::operator=(const Cat &copy) {
	Animal::operator=(copy);
	std::cout << "Assignment operator for Cat called." << std::endl;
	return (*this);
}

const std::string &Cat::getType(void) const {
	return (this->_type);
}

void Cat::setType(const std::string &type) {
	this->_type = type;
}

void Cat::makeSound(void) const {
	std::cout << "Cat From Animal goes Meow!" << std::endl;
}

Brain &Cat::getBrain(void) const {
	return (*this->_brain);
}

void Cat::setBrain(const Brain &brain) {
	*this->_brain = brain;
}
