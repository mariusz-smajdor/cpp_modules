#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " was created!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << getName() << " was destroyed!" << std::endl;
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