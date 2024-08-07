#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>

class	Contact {
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_number;
		std::string	_darkestSecret;

	public:
		Contact(void);
		~Contact(void);

		const std::string getFirstname(void) const;
		const std::string getLastname(void) const;
		const std::string getNickname(void) const;
		const std::string getNumber(void) const;
		const std::string getDarkestSecret(void) const;
		void setFirstname(std::string str);
		void setLastname(std::string str);
		void setNumber(std::string const str);
		void setNickname(std::string const str);
		void setDarkestSecret(std::string const str);
};

#endif