#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

// Constructors and Destructor

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request Form", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), _target(copy._target) {
    std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm " << this->getName() << " destroyed" << std::endl;
}

// Operators

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    Form::operator=(copy);
    if (this != &copy) {
        this->_target = copy._target;
    }
    return *this;
}

// Member functions

void RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const {
    int success = rand() % 2;
    srand(time(NULL));
    if (bureaucrat.getGrade() > this->getExecGrade()) {
        throw Form::GradeTooLowException();
    }
    if (this->getSignGrade() < 72 && this->getExecGrade() < 45 && success) {
        std::cout << "RobotomyRequestForm " << this->_target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "RobotomyRequestForm " << this->_target << " has failed to be robotomized" << std::endl;
    }
}

// Operators

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &robotomyRequestForm) {
    out << "RobotomyRequestForm " << robotomyRequestForm.getName() << " is " << (robotomyRequestForm.getSigned() ? "" : "not ") << "signed";
    return out;
}