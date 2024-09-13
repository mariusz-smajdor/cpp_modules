#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

private:
    std::string _name;

public:
    Zombie(const std::string& _name);

    ~Zombie();

    void announce() const;

};

#endif
