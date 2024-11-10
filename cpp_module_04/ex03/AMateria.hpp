#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

		// Constructors and Destructors
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);
	public:
		// Constructors and Destructors
		virtual ~AMateria(void);

		// Operator Overload
		const AMateria &operator=(const AMateria &copy);

		// Getters and Setters
		const std::string &getType(void) const;

		// Member Functions
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target) = 0;
};
