#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "../Contact/Contact.class.hpp"

class	PhoneBook {
	private:
		int		_index;
		Contact	_contactList[8];

		int _getContactsSize(void) const;
		void _listFullContactInfo(int index);
		void _displayContacts(void);
		std::string _truncateString(std::string str);
		std::string _processInput(std::string input, bool isNumber, bool isName);
		std::string _trim(std::string str);
		
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(void);
		void searchContact(void);
};

#endif