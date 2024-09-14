#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _scavHitPoints(100), _scavEnergyPoints(50), _scavAttackDamage(20) {
    std::cout << "ScavTrap " << name << " was created!" << std::endl;
    _hitPoints = _scavHitPoints;
	_energyPoints = _scavEnergyPoints;
	_attackDamage = _scavAttackDamage;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << getName() << " was destroyed!" << std::endl;
}

int ScavTrap::getScavEnergyPoints(void) const {
    return _scavEnergyPoints;
}

void ScavTrap::attack(const std::string& target) {
    if (getHitPoints() <= 0 || getEneryPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " is unable to attack!" << std::endl;
        return ;
    }
    setEnergyPoints(getEneryPoints() - 1);
    std::cout << "ScavTrap " << getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}
