#pragma once

#include <iostream>
#include <ostream>

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        // Constructors and Destructor
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat(void);

        // Operators
        const Bureaucrat &operator=(const Bureaucrat &copy);

        // Getters and Setters
        const std::string &getName(void) const;
        const int &getGrade(void) const;

        // Member functions
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(const Form &form);

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what(void) const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);