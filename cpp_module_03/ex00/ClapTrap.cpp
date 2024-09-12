// 	std::string _name;
// 	int hitPoints = 10;
// 	int energyPoints = 10;
// 	int attackDamage = 0;

#include "ClapTrap.hpp"

// Constructor and Destructor

ClapTrap::ClapTrap(std::string name) : _name(name) {
    std::cout << name << " was created!" << std::endl; 
}

ClapTrap::~ClapTrap(void) {
    std::cout << this->getName() << " was destroyed!" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const {
    return this->_name;
}
