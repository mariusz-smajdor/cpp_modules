#pragma once

#include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		// Constructors and Destructors
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		// Operator Overloads
		const Cure &operator=(const Cure &copy);

		// Member Functions
		virtual AMateria *clone(void) const;
		void use(ICharacter &target);
};
