#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	private:
		Brain *_brain;
	public:
		// Constructors and Destructors
		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);

		// Operator Overload
		const Dog &operator=(const Dog &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		Brain &getBrain(void) const;
		void setType(const std::string &type);
		void setBrain(const Brain &brain);

		// Member Functions
		void makeSound(void) const;
};

class Cat: public Animal {
	private:
		Brain		*_brain;
	public:
		// Constructors and Destructors
		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);

		// Operator Overload
		const Cat &operator=(const Cat &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		Brain &getBrain(void) const;
		void setType(const std::string &type);
		void setBrain(const Brain &brain);

		// Member Functions
		void makeSound(void) const;
};
