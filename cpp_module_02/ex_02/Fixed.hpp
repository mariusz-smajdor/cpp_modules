#include <iostream>

class Fixed {
    
private:
	int _value;
	static const int fractBits;

public:
	Fixed();

	int getValue() const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
