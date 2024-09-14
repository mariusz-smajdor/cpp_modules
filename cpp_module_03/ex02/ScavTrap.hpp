#include "ClapTrap.hpp"

#pragma once

class ScavTrap : public ClapTrap {

public:
    ScavTrap(std::string name);
    ~ScavTrap(void);

	void attack(const std::string& target);
    void guardGate(void);

};