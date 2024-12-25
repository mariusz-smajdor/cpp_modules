#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors and Destructor

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon Form", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), _target(copy._target) {
    std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm " << this->getName() << " destroyed" << std::endl;
}

// Operators

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    Form::operator=(copy);
    if (this != &copy) {
        this->_target = copy._target;
    }
    return *this;
}

// Member functions

void PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const {
    if (bureaucrat.getGrade() > this->getExecGrade()) {
        throw Form::GradeTooLowException();
    }
    std::cout << this->_target << " has been pardoned by " << bureaucrat.getName() << std::endl;
}

// Operators

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form) {
    out << "PresidentialPardonForm " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed";
    return out;
}
