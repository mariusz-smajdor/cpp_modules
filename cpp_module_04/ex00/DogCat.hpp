#pragma once

#include "Animal.hpp"

class Dog: public Animal {
    private: 
        std::string _type;
    public:
        // Constructors and Destructor
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &copy);
		~Dog(void);

		// Basic Operators
		const Dog &operator=(const Dog &copy);

		// Getters and Setters
		std::string const &getType(void) const;
		void setType(const std::string &type);

		// Member Functions
		void makeSound(void) const;
};

class Cat: public Animal {
	private:
		std::string	_type;
	public:
		// Constructors and Destructors
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &copy);
		~Cat(void);

		// Operator overloads
		const Cat &operator=(Cat const &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		void setType(const std::string &type);

		// Member Functions
		void makeSound(void) const;
};
