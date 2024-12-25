#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        Form form("form", 1, 1);

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat("bureaucrat", 150);
        Form form("form", 150, 150);

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern intern;
        Form *form1 = intern.createForm("shrubbery creation", "target");
        Form *form2 = intern.createForm("robotomy request", "target");
        Form *form3 = intern.createForm("presidential pardon", "target");
        Form *form4 = intern.createForm("undefined", "target");

        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;
        std::cout << *form4 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}