#include <iostream>
#include "PhoneBook/PhoneBook.class.hpp"

int main(void) {
    PhoneBook phoneBook;
    std::string userInput;

    std::cout << "--- Phone Book ---" << std::endl;
    while (true) {
        std::cout << "What would you like to do? (ADD, SEARCH, EXIT)" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);
        if (userInput == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else if  (userInput == "ADD") {
            phoneBook.addContact();
        } else {
            std::cout << "Invalid command! Please try again." << std::endl;
        }
    }
    return 0;
}