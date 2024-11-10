#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {
	std::cout << "Cure created with default constructor" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure destroyed" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy) {
	std::cout << "Cure copied" << std::endl;
}

Cure const	&Cure::operator=(const Cure &copy) {
	this->_type = copy._type;
	return (*this);
}

AMateria *Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
