#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
