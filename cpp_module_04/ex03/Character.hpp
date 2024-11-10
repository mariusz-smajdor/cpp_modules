#pragma once

#include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string	_name;
		AMateria *_inventory[4];
	public:
		// Constructors and Destructors
		Character(void);
		Character(const std::string &name);
		Character(const Character &copy);
		~Character(void);

		// Operator Overloads
		const Character &operator=(const Character &copy);

		// Getters and Setters
		const std::string &getName(void) const;
		void setName(const std::string &name);

		// Member Functions
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
		int inInventory(AMateria *m);
};
