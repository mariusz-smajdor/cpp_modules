#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b;

    b.setRawBits(11);
    std::cout << a << std::endl;
    std::cout << (a < b) << std::endl;
    return 0;
}
