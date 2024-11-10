#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria	*_learnInventory[4];
	public:
		// Constructors and Destructors
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		~MateriaSource(void);

		// Operator Overloads
		const MateriaSource &operator=(const MateriaSource &copy);

		// Member Functions
		virtual void learnMateria(AMateria *materia);
		virtual AMateria* createMateria(const std::string &type);
		int inLearnInventory(AMateria *materia);
};
