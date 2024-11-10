#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain created with default constructor." << std::endl;
}

Brain::Brain(const Brain &copy) {
	*this = copy;
	std::cout << "Brain copied." << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed." << std::endl;
}

const Brain &Brain::operator=(const Brain &copy) {
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	std::cout << "Assignment operator for Brain called." << std::endl;
	return (*this);
}

const std::string &Brain::getIdea(const int &index) const {
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

void Brain::setIdea(const std::string &idea, const int &index) {
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}
