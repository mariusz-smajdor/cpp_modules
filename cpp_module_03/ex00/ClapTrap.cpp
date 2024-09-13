// 	std::string _name;
// 	int hitPoints = 10;
// 	int energyPoints = 10;
// 	int attackDamage = 0;

#include "ClapTrap.hpp"

// Constructor and Destructor

ClapTrap::ClapTrap(std::string name) : _name(name),
                                       _hitPoints(10),
                                       _energyPoints(10),
                                       _attackDamage(0) {
    std::cout << name << " was created!" << std::endl; 
}

ClapTrap::~ClapTrap(void) {
    std::cout << _name << " was destroyed!" << std::endl;
}

// Member functions

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is unable to attack!" << std::endl; 
    }

    _energyPoints--;

    std::cout << "ClapTrap " << _name << " attacks "
              << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}