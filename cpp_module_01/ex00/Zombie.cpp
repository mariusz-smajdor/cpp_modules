#include "Zombie.hpp"

// Constructor
Zombie::Zombie(const std::string& name) : _name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

// Member function
void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
