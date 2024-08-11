#include <iostream>
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

// Public members

void Harl::complain(std::string level) {
	typedef void (Harl::*HarlMemFn)(void);
    HarlMemFn functions[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Unknown level." << std::endl;
}
