#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "../Contact/Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		Contact	_contactList[8];

		int _getContactsSize(void) const;
		void _displayContacts(void) const;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(void);
		void searchContact(void);
};

#endif