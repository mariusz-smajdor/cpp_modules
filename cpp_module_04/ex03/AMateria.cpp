#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): _type(type) {
	std::cout << "AMateria object created" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
	std::cout << "AMateria object copied" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria object destroyed" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &copy) {
	this->_type = copy._type;
	std::cout << "AMateria Assignment Operator Called" << std::endl;
	return (*this);
}

const std::string &AMateria::getType(void) const {
	return (this->_type);
}
