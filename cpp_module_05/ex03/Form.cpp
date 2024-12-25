#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Constructors and Destructor

Form::Form(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
    std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw Form::GradeTooLowException();
    }
    std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
    std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

// Getters and Setters

const std::string &Form::getName(void) const {
    return this->_name;
}

const bool &Form::getSigned(void) const {
    return this->_signed;
}

const int &Form::getSignGrade(void) const {
    return this->_signGrade;
}

const int &Form::getExecGrade(void) const {
    return this->_execGrade;
}

// Member functions

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
        throw Form::GradeTooLowException();
    }
    this->_signed = true;
}

Form *Form::createForm(const std::string &name, const std::string &target) {
    Form *form = NULL;

    if (name == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    } else if (name == "robotomy request") {
        form = new RobotomyRequestForm(target);
    } else if (name == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    } else {
        throw Intern::FormNotFoundException();
    }

    return form;
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Operators

const Form &Form::operator=(const Form &copy) {
    if (this != &copy) {
        this->_signed = copy._signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is ";
    if (form.getSigned()) {
        out << "signed";
    } else {
        out << "not signed";
    }
    out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
    return out;
}