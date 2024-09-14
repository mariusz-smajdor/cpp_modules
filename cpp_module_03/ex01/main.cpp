#include "ScavTrap.hpp"

int main() {
    ScavTrap Super("Super");
    Super.attack("Maciej Debil");
    Super.takeDamage(4);
    Super.beRepaired(1);
    return 0;
}