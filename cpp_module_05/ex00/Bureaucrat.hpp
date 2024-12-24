#include <iostream>
#include <ostream>

#pragma once

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
        Bureaucrat const &operator=(Bureaucrat const &copy);

        // Getters and Setters
        const std::string &getName(void) const;
        const int &getGrade(void) const;

        // Member functions
        void incrementGrade(void);
        void decrementGrade(void);

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);