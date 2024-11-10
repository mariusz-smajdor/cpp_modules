#pragma once

#include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		// Constructors and Destructors
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

		// Operator Overload
		const WrongAnimal &operator=(const WrongAnimal &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		void setType(const std::string &type);

		// Member functions
		void makeSound(void) const;
};

class WrongCat: public WrongAnimal {
	private:
		std::string	_type;
	public:
		// Constructors and Destructors
		WrongCat(void);
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &copy);
		~WrongCat(void);

		// Operator Overload
		const WrongCat &operator=(const WrongCat &copy);

		// Getters and Setters
		const std::string &getType(void) const;
		void setType(const std::string &type);

		// Member Function
		void makeSound(void) const;
};

