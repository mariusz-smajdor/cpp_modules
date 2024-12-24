#include "Bureaucrat.hpp"

int main(void) {
    {
        try {
            Bureaucrat b1("b1", 1);
            std::cout << b1 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    {
        try {
            Bureaucrat b2("b2", 150);
            std::cout << b2 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    {
        try {
            Bureaucrat b3("b3", 0);
            std::cout << b3 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    {
        try {
            Bureaucrat b4("b4", 151);
            std::cout << b4 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    {
        try {
            Bureaucrat b5("b5", 2);
            Bureaucrat b6(b5);
            std::cout << b6 << std::endl;
            b5.incrementGrade();
            std::cout << b6 << std::endl;
            b5.incrementGrade();
            std::cout << b6 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}