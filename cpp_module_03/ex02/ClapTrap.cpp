#include "ClapTrap.hpp"

// Constructor and Destructor

ClapTrap::ClapTrap(std::string name) : _name(name),
                                       _hitPoints(100),
                                       _energyPoints(100),
                                       _attackDamage(30) {
    std::cout << name << " was created!" << std::endl; 
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

// Getters and setters

std::string ClapTrap::getName(void) const {
    return _name;
}

int ClapTrap::getHitPoints(void) const {
    return _hitPoints;
}

int ClapTrap::getEneryPoints(void) const {
    return _energyPoints;
}

int ClapTrap::getAttackDamage(void) const {
    return _attackDamage;
}

void ClapTrap::setEnergyPoints(int amount) {
    _energyPoints = amount;
}

// Member functions

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is unable to attack!" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks "
              << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    _hitPoints -= amount;
    std::cout << "Clap trap " << _name << " took "
               << amount << " points of damage!\n"
               << "Current health: " << _hitPoints << std::endl;
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is unable to repair!" << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs himself gaining "
          << amount << " points of health!\n" 
          << "Current health: " << _hitPoints <<  std::endl;
}