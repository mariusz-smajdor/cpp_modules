#pragma once

#include <iostream>

class Weapon {

private:
    std::string _type;

public:
    Weapon(const std::string type);
    ~Weapon();

    const std::string& getType() const;
    void setType(const std::string type);

};
