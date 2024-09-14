#pragma once

#include <iostream>

class ClapTrap {

protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap(std::string name);
	~ClapTrap(void);

	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEneryPoints(void) const;
	int getAttackDamage(void) const;
	void setEnergyPoints(int amount);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};
