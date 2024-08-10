#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    Zombie* horde = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
