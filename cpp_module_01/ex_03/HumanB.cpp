#include "HumanB.hpp"

HumanB::HumanB(const std::string _name) : _name(_name), _weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::attack() const {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with" << std::endl;
    }
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}
