#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void) {
	std::cout << "IMateriaSource object created with default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy) {
	*this = copy;
	std::cout << "IMateriaSource object copied" << std::endl;
}

const IMateriaSource &IMateriaSource::operator=(IMateriaSource &copy) {
	(void)copy;
	std::cout << "IMateriaSource Assignment Operator Called" << std::endl;
	return (*this);
}
