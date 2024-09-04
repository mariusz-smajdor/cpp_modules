#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b;

    b.setRawBits(11);

    Fixed c = a + b;

    std::cout << a << std::endl;
    std::cout << c << std::endl;

    return 0;
}
