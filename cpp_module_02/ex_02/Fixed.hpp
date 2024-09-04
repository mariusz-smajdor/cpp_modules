#include <iostream>

class Fixed {
    
private:
	int _value;
	static const int fractBits;

public:
	Fixed();

	int getRawBits(void) const;
	void setRawBits(const int raw);
	bool operator>(const Fixed& other) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
