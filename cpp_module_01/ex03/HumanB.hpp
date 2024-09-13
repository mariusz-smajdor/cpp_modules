#include "Weapon.hpp"

class HumanB {

private:
    const std::string _name;
    Weapon* _weapon;

public:
    HumanB(const std::string _name);
    ~HumanB();

    void setWeapon(Weapon& weapon);
    void attack() const;

};
