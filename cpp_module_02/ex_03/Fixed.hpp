#include <iostream>
#include <cmath>

class Fixed {
    
private:
	int _value;
	static const int _fractBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int intPart);
	Fixed(const float floatPart);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

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
