#include "ScavTrap.hpp"

int main() {
    ScavTrap Super("Super");
    Super.attack("Maciej Debil");
    Super.takeDamage(4);
    Super.beRepaired(1);
    std::cout << "\n\n\n";
    ScavTrap Scav("Scav");
    std::cout << "\n" << Scav.getHitPoints() << "\n" << Scav.getEneryPoints() << "\n" << Scav.getAttackDamage() << std::endl;
    Super.guardGate();
    ClapTrap Super2("Super2");
    std::cout << "\n" << Super2.getHitPoints() << "\n" << Super2.getEneryPoints() << "\n" << Super2.getAttackDamage() << std::endl;

    return 0;
}