#include "Intern.hpp"

// Constructors and Destructor

Intern::Intern(void) {
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void)copy;
    std::cout << "Intern was copied" << std::endl;
    *this = copy;
}

Intern::~Intern(void) {
    std::cout << "Intern destroyed" << std::endl;
}

// Operators

const Intern &Intern::operator=(const Intern &copy) {
    (void)copy;
    return *this;
}

// Member functions

Form *Intern::createForm(const std::string &type, const std::string &target) {
    Form *form = Form::createForm(type, target);

    std::cout << "Intern creates " << form->getName() << std::endl;

    if (type == "Shrubbery Creation Form") {
        form = new ShrubberyCreationForm(target);
    } else if (type == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (type == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else {
        throw Intern::FormNotFoundException();
    }
    return form;
}

// Exceptions

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}