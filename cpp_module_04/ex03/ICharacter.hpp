#pragma once

#include "AMateria.hpp"

class ICharacter {
	protected:
		// Constructors and Destructors
		ICharacter(void);
		ICharacter(const ICharacter &copy);

		// Operator Overloads
		const ICharacter &operator=(const ICharacter &copy);
	public:
		// Constructors and Destructors
		virtual	~ICharacter() {}

		// Getters and Setters
		virtual const std::string &getName() const = 0;

		// Member Functions
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};
