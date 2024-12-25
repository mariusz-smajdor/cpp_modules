#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors and Destructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("Shrubbery Creation", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy), _target(copy._target) {
    std::cout << "ShrubberyCreationForm " << this->getName() << " was copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed" << std::endl;
}

// Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    this->Form::operator=(copy);
    this->_target = copy._target;
    return *this;
}

// Member Functions
void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const {
    if (this->getSignGrade() < 72 || this->getExecGrade() < 45) {
        throw ShrubberyCreationForm::GradeTooLowException();
    }

    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());


    file << "      .     .  .      +     .      .          .\n";
    file << "     .       .         ##       .           .\n";
    file << "        .      .     ##  ##             .      .\n";
    file << "     .        .   ##   ##   .          .\n";
    file << "             . ##    ##.        .          .\n";
    file << "       .     ##    ##           .        .\n";
    file << "         . ##    ##.        .          .\n";
    file << "    .      ##     ##     .     .        .\n";
    file << "  .         ##     ##.          .        .\n";
    file << "            ##       ##.     .        .\n";
    file << "  .        ##         ##         .       .\n";
    file << "           ##         ##.         .      .\n";

    file.close();

    std::cout << "ShrubberyCreationForm << " << this->getName() << " has been executed by " << bureaucrat.getName() << std::endl;
}

// Operators

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubberyCreationForm) {
    out << "ShrubberyCreationForm << " << shrubberyCreationForm.getName() << " is " << (shrubberyCreationForm.getSigned() ? "" : "not ") << "signed";
    return out;
}