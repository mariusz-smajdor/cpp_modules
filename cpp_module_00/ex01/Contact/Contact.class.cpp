// Constructor and destructor

Contact::Contact(void) : _firstname(""),
						_lastname(""),
                        _nickname(""),
						_number(""), 
                        _darkestSecret("") {
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

void Contact::setNickname(std::string str) {
    this->_nickname = str;
}

void Contact::setNumber(std::string str) {
    this->_number = str;
}

void Contact::setDarkestSecret(std::string str) {
    this->_darkestSecret = str;
}

// GETTERS

std::string Contact::getFirstname(void) const {
    return this->_firstname;
}

std::string Contact::getLastname(void) const {
    return this->_lastname;
}

std::string Contact::getNickname(void) const {
   return this->_nickname;
}

std::string Contact::getNumber(void) const {
    return this->_number;
}

std::string Contact::getDarkestSecret(void) const {
    return this->_darkestSecret;
}
