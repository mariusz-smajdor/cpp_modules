#include <iostream>

// std::string getUserInput() {

// }

int main(void) {
    std::string userInput;

    std::cout << "--- Phone Book ---" << std::endl;
    while (true) {
        std::cout << "What would you like to do? (ADD, SEARCH, EXIT)" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);
        if (userInput == "EXIT") {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        std::cout << "You entered: " << userInput << std::endl;
    }
    return 0;
}