#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    Bureaucrat bureaucrat("Bureaucrat", 1);
    ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
    RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
    PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");

    std::cout << bureaucrat << std::endl;
    std::cout << shrubberyCreationForm << std::endl;
    std::cout << robotomyRequestForm << std::endl;
    std::cout << presidentialPardonForm << std::endl;

    try {
        shrubberyCreationForm.beSigned(bureaucrat);
        robotomyRequestForm.beSigned(bureaucrat);
        presidentialPardonForm.beSigned(bureaucrat);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << shrubberyCreationForm << std::endl;
    std::cout << robotomyRequestForm << std::endl;
    std::cout << presidentialPardonForm << std::endl;

    try {
        shrubberyCreationForm.beExecuted(bureaucrat);
        robotomyRequestForm.beExecuted(bureaucrat);
        presidentialPardonForm.beExecuted(bureaucrat);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}