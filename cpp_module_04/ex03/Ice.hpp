#pragma once

#include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		// Constructors and Destructors
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);

		// Operator Overloads
		const Ice &operator=(const Ice &copy);

		// Member Functions
		virtual AMateria *clone(void) const;
		void use(ICharacter &target);
};
