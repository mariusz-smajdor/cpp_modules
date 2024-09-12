#include <iostream>

class ClapTrap {

private:
	std::string _name;
	int hitPoints = 10;
	int energyPoints = 10;
	int attackDamage = 0;

public:
	ClapTrap(std::string name);
	~ClapTrap(void);

	std::string getName(void) const;

	// void attack(const std::string& target);
	// void takeDamage(unsigned int amount);
	// void beRepaired(unsigned int amount);

};