#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
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

void PhoneBook::_listFullContactInfo(int index) {
	std::cout << "Your contact's information:" << std::endl;
	std::cout << "First name: " << this->_contactList[index].getFirstname() << std::endl;
	std::cout << "Last name: " << this->_contactList[index].getLastname() << std::endl;
	std::cout << "Nickname: " << this->_contactList[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contactList[index].getNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contactList[index].getDarkestSecret() << std::endl;
}

void PhoneBook::_displayContacts() const {
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

    if (this->_getContactsSize() == 0) {
        std::cout << "The contact list is empty!" << std::endl;
        return ;
    }

	for (int i = 0; i < this->_getContactsSize(); i++) {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << this->_contactList[i].getFirstname() << "|";
        std::cout << std::setw(10) << this->_contactList[i].getLastname() << "|";
        std::cout << std::setw(10) << this->_contactList[i].getNickname() << "|" << std::endl;
    }
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

std::string	PhoneBook::_trim(std::string str) {
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

std::string PhoneBook::_processInput(std::string input, bool isNumber, bool isName) {
    input = this->_trim(input);

    if (input.empty()) {
        std::cout << "Your input can't be empty!" << std::endl;
        return "";
    }
    if (isNumber && !std::all_of(input.begin(), input.end(), ::isdigit)) {
        std::cout << "Please enter a valid number!" << std::endl;
        return "";
    }
    if (isName && !std::all_of(input.begin(), input.end(), ::isalpha)) {
        std::cout << "Please enter a valid name!" << std::endl;
        return "";
    }
    return input;
}

/* Public */

void PhoneBook::addContact(void) {
    if (this->_index == 8) {
        std::cout << "The contact list is full! Replacing the oldest contact..." << std::endl;
        this->_index = 0;
    }

    std::string firstname, lastname, nickname, number, darkestSecret;

    std::cout << "--- Add Contact ---" << std::endl;
    do {
        std::cout << "Enter the contact's first name: ";
        std::getline(std::cin, firstname);
        this->_contactList[this->_index].setFirstname(firstname);
    } while ((firstname = this->_processInput(firstname, false, true)).empty());
    do {
        std::cout << "Enter the contact's last name: ";
        std::getline(std::cin, lastname);
        this->_contactList[this->_index].setLastname(lastname);
    } while ((lastname = this->_processInput(lastname, false, true)).empty());
    do {
        std::cout << "Enter the contact's nickname: ";
        std::getline(std::cin, nickname);
        this->_contactList[this->_index].setNickname(nickname);
    } while ((nickname = this->_processInput(nickname, false, false)).empty());
    do {
        std::cout << "Enter the contact's phone number: ";
        std::getline(std::cin, number);
        this->_contactList[this->_index].setNumber(number);
    } while ((number = this->_processInput(number, true, false)).empty());
    do {
        std::cout << "Enter the contact's darkest secret: ";
        std::getline(std::cin, darkestSecret);
		this->_contactList[this->_index].setDarkestSecret(darkestSecret);
    } while ((darkestSecret = this->_processInput(darkestSecret, false, false)).empty());

    std::cout << this->_contactList[this->_index].getFirstname() << " was added to the contact list!" << std::endl;
    this->_index++;
}

void PhoneBook::searchContact() {
    std::string enteredIndex;

    this->_displayContacts();

    int index;
    do {
        std::cout << std::endl << "Enter the index of the contact you would like to view: ";
        std::getline(std::cin, enteredIndex);
        if (enteredIndex.empty()
			|| !std::all_of(enteredIndex.begin(), enteredIndex.end(), ::isdigit)
			|| std::stoi(enteredIndex) > this->_getContactsSize() - 1) {
            std::cout << "Please enter a valid index!" << std::endl;
            continue;
        }
        index = std::stoi(enteredIndex);
    } while (index < 0 || index >= this->_getContactsSize());
    this->_listFullContactInfo(index);
}
