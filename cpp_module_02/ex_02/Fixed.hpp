#include <iostream>

class Fixed {
    
private:
	int _value;
	static const int fractBits;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int intPart);
	Fixed(const float floatPart);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
