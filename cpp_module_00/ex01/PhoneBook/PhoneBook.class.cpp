#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

/*	Constructor	*/
PhoneBook::PhoneBook(void) : _index(0) {
	return ;
}

/*	Destructor	*/
PhoneBook::~PhoneBook(void) {
	return ;
}

/*	Private	*/

int PhoneBook::_getContactsSize(void) const {
    int i = 0;

    while (i < 8 && this->_contactList[i].getFirstname() != "")
        i++;
    return i;
}

void PhoneBook::_displayContacts() const {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

	for (int i = 0; i < this->_getContactsSize(); i++) {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << this->_contactList[i].getFirstname() << "|";
        std::cout << std::setw(10) << this->_contactList[i].getLastname() << "|";
        std::cout << std::setw(10) << this->_contactList[i].getNickname() << "|" << std::endl;
    }
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

/* Public */

void PhoneBook::addContact(void) {
    if (this->_index == 8) {
        std::cout << "The contact list is full! Replacing the first contact..." << std::endl;
        this->_index = 0;
    }

    std::string firstname, lastname, nickname, number, darkestSecret;

    std::cout << "--- Add Contact ---" << std::endl;
    std::cout << "Enter the contact's first name: ";
    std::getline(std::cin, firstname);
    std::cout << "Enter the contact's last name: ";
    std::getline(std::cin, lastname);
    std::cout << "Enter the contact's nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter the contact's phone number: ";
    std::getline(std::cin, number);
    std::cout << "Enter the contact's darkest secret: ";
    std::getline(std::cin, darkestSecret);

    this->_contactList[this->_index].setFirstname(firstname);
    this->_contactList[this->_index].setLastname(lastname);
    this->_contactList[this->_index].setNickname(nickname);
    this->_contactList[this->_index].setNumber(number);
    this->_contactList[this->_index].setDarkestSecret(darkestSecret);

    std::cout << this->_contactList[this->_index].getFirstname() << " was added to the contact list!" << std::endl;
    this->_index++;
}

void PhoneBook::searchContact(int index) {
    (void)index;

    this->_displayContacts();
}

