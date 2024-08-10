#include "HumanA.hpp"

HumanA::HumanA(const std::string _name, Weapon& _weapon) : _name(_name), _weapon(_weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
