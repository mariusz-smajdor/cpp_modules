#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}
Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
    return this._type;
}

void Weapon::setType(const std::string& type) {
    this._type = type;
}

// class Weapon {

// public:
//     Weapon(const std::string& type);
//     ~Weapon();

//     const std::string& getType() const;
//     void setType(const std::string& type);

// private:
//     std::string _type;

// }