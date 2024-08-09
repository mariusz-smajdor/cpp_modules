#include "Zombie.hpp"
// Constructors

Zommbie::Zombie(std::string name) : _name(name) {}

~Zombie::Zombie() {
	std::cout << _name << " is destroyed" << std::endl;
}

void announce() const {
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

