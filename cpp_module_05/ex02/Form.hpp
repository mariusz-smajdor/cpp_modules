#pragma once

#include <iostream>
#include <ostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        // Constructors and Destructor
        Form(void);
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &copy);
        ~Form(void);

        // Operators
        const Form &operator=(const Form &copy);

        // Getters and Setters
        const std::string &getName(void) const;
        const bool &getSigned(void) const;
        const int &getSignGrade(void) const;
        const int &getExecGrade(void) const;

        // Member functions
        void beSigned(const Bureaucrat &bureaucrat);

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);
