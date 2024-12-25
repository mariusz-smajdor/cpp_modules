#pragma once

#include <stdlib.h>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form {
    private:
        std::string _target;

    public:
        // Constructors and Descructor
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm(void);

        // Operators
        const RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

        // Member functions
        void beExecuted(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &robotomyRequestForm);