#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap Super("Super");
    Super.attack("Maciej Debil");
    Super.takeDamage(4);
    Super.beRepaired(1);
    Super.guardGate();

    std::cout << "\n\n\n";

    FragTrap Super2("Super2");
    Super2.attack("Maciej 🤡");
    Super2.takeDamage(3);
    Super2.beRepaired(2);
    Super2.highFivesGuys();

    std::cout << "\n\n\n";
    ScavTrap Scav("Scav");
    std::cout << "\n" << Scav.getHitPoints() << "\n" << Scav.getEneryPoints() << "\n" << Scav.getAttackDamage() << std::endl;
    
    std::cout << "\n";
    FragTrap Frag("Frag");
    std::cout << "\n" << Frag.getHitPoints() << "\n" << Frag.getEneryPoints() << "\n" << Frag.getAttackDamage() << std::endl;
    return 0;
}