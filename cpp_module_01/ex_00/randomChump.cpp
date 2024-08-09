#include "Zombie.hpp"

void randomChump(const std::string& name) {
    Zombie zombie(name);
    zombie.announce();
}