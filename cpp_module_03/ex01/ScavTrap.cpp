#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " was created!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << getName() << " was destroyed!" << std::endl;
}