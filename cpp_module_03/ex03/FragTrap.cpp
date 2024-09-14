#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " was created!" << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << getName() << " was destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << getName() << " says: High five guys!" << std::endl;
}