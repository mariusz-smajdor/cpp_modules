#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " was created!" << std::endl;
    _hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << getName() << " was destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << getName() << " says: High five guys!" << std::endl;
}