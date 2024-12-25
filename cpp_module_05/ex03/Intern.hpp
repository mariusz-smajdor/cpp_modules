#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern {
    public:
        // Constructors and Destructor
        Intern(void);
        Intern(const Intern &copy);
        ~Intern(void);

        // Operators
        const Intern &operator=(const Intern &copy);

        // Member functions
        Form *createForm(const std::string &formName, const std::string &target);

        // Exceptions
        class FormNotFoundException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};