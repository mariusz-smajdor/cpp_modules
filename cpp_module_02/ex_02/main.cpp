#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b;

    a.setRawBits(0);
    std::cout << a << std::endl;
    std::cout << (a > b) << std::endl;
    return 0;
}
