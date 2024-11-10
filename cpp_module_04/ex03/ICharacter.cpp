#include "ICharacter.hpp"

ICharacter::ICharacter(void) {
	std::cout << "ICharacter object created with default constructor" << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy) {
	*this = copy;
	std::cout << "ICharacter object copied" << std::endl;
}

const ICharacter &ICharacter::operator=(const ICharacter &copy) {
	(void)copy;
	std::cout << "ICharacter Assignment Operator Called" << std::endl;
	return (*this);
}
