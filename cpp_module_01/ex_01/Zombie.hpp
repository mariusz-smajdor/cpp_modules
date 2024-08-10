#include <iostream>

class Zombie {

public:
    Zombie();

    Zombie(const std::string& _name);

    ~Zombie();

    void announce() const;

private:
    std::string _name;

};