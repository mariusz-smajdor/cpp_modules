#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

private:
    int _scavHitPoints;
    int _scavEnergyPoints;
    int _scavAttackDamage;

public:
    ScavTrap(std::string name);
    ~ScavTrap(void);

    int getScavEnergyPoints(void) const;

	void attack(const std::string& target);
    void guardGate(void);

};