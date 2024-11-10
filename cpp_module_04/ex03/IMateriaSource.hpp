#pragma once

#include "AMateria.hpp"

class IMateriaSource {
	protected:
		// Constructors and Destructors
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &copy);

		// Operator Overloads
		const IMateriaSource &operator=(const IMateriaSource &copy);
	public:
		// Constructors and Destructors
		virtual ~IMateriaSource() {}

		// Member Functions
		virtual void learnMateria(AMateria *materia) = 0;
		virtual AMateria* createMateria(const std::string &type) = 0;
};
