#pragma once

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form {
    private:
        std::string _target;

    public:
        // Constructors and Destructor
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &copy);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm(void);

        // Operators
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

        // Member Functions
        void beExecuted(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);