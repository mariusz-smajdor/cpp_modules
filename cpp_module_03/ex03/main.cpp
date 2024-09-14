#include "DiamondTrap.hpp"

int main() {
    DiamondTrap Super("Super");

    std::cout << "\n" << Super.getHitPoints() << "\n" << Super.getEneryPoints() << "\n" << Super.getAttackDamage() << std::endl;
    
    ScavTrap Scav("Scav");
    std::cout << "\n" << Scav.getHitPoints() << "\n" << Scav.getEneryPoints() << "\n" << Scav.getAttackDamage() << std::endl;
    
    return 0;
}