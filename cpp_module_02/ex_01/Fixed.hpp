#pragma once

#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _fractBits = 8;

	public:
		Fixed(void);
        Fixed(const int intPart);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(const int raw);
};
