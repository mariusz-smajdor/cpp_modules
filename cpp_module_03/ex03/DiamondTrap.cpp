#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(name + "_clap_name"),
	  FragTrap(name + "_clap_name"),
	  _name(name) {
    std::cout << "DiamondTrap " << name << " was created!" << std::endl; 
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::getScavEnergyPoints();
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}