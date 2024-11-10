#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	_type;
	public:
		// Constructors and Destructors
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		// Assignment operator
		const Animal &operator=(const Animal &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		void setType(const std::string &type);
		virtual Brain &getBrain(void) const = 0;

		// Member Functions
		virtual void makeSound(void) const;
};
