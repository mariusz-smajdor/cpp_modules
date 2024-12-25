#pragma once

#include <fstream>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form {
    private:
        std::string _target;
    
    public:
        // Constructors and Destructor
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm(void);

        // Operators
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        // Member Functions
        void beExecuted(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);