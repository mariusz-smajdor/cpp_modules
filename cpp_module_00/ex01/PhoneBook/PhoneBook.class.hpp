#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "../Contact/Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		Contact	_contactList[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(void);
};

#endif