// Constructor and destructor

Contact::Contact(void) : _firstname(""),
						_lastname(""),
						_number("") {
	return ;
}

Contact::~Contact(void) {
	return ;
}

// SETTERS

void Contact::setFirstname(std::string str) {
	this->_firstname = str;
}

void Contact::setLastname(std::string str) {
    this->_lastname = str;
}

void Contact::setNumber(std::string str) {
    this->_number = str;
}

// GETTERS

std::string Contact::getFirstname(void) const {
    return this->_firstname;
}

std::string Contact::getLastname(void) const {
    return this->_lastname;
}

std::string Contact::getNumber(void) const {
    return this->_number;
}
