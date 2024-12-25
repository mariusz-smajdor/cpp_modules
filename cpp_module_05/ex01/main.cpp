#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Form form("Form", 0, 0);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Form form("Form", 151, 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Form form("Form", 1, 1);
        Bureaucrat bureaucrat("Bureaucrat", 2);
        form.beSigned(bureaucrat);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Form form("Form", 1, 1);
        Bureaucrat bureaucrat("Bureaucrat", 0);
        form.beSigned(bureaucrat);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}