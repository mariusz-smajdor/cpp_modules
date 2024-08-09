#include "Zombie.hpp"

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

int main() {
    // create a zombie on the heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // free the heap memory

    // create a zombie on the stack
    randomChump("StackZombie");

    return 0;
}
