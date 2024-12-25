#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and Destructor

Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(150) {
    std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    this->_grade = grade;
    std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat " << this->_name << " was copied " << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

// Operators

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy) {
    // this->_name = copy._name;
    this->_grade = copy._grade;
    return *this;
}

// Getters and Setters

const std::string &Bureaucrat::getName(void) const {
    return this->_name;
}

const int &Bureaucrat::getGrade(void) const {
    return this->_grade;
}

// Member functions

void Bureaucrat::incrementGrade(void) {
    if (this->_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

void Bureaucrat::signForm(const Form &form) {
    if (form.getSignGrade() < this->_grade) {
        std::cout << this->_name << " cannot sign " << form.getName()
                  << " because grade is too low" << std::endl;
    } else {
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Insertion overload

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return out;
}   
