#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {
	std::cout << "Ice created with default constructor" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice destroyed" << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy) {
	std::cout << "Ice copied" << std::endl;
}

const Ice &Ice::operator=(const Ice &copy) {
	this->_type = copy._type;
	return (*this);
}

AMateria *Ice::clone(void) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
