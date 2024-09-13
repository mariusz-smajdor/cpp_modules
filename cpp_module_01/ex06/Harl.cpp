#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

// Private members

void Harl::_debug() {
    std::cout << "Debug message" << std::endl;
}

void Harl::_info() {
    std::cout << "Info message" << std::endl;
}

void Harl::_warning() {
    std::cout << "Warning message" << std::endl;
}

void Harl::_error() {
    std::cout << "Error message" << std::endl;
}

int Harl::_getLevelIndex(std::string& level) {
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            return i;
        }
    }
    return -1;
}

// Public members

void Harl::complain(std::string level) {
    int index = this->_getLevelIndex(level);

    switch (index) {
        case 0:
            this->_debug();
            // Intentional fallthrough
        case 1:
            this->_info();
            // Intentional fallthrough
        case 2:
            this->_warning();
            // Intentional fallthrough
        case 3:
            this->_error();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
}
